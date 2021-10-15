/*
Il dispositivo di cronometraggio di una gara a tappe genera,
all’arrivo di ogni tappa, una lista dinamica con i numeri di maglia
e i tempi di tappa dei vari concorrenti.

Un’altra lista conserva la classifica generale della gara,
con i numeri di maglia e il tempo totale di percorrenza.

I dati hanno la seguente struttura:
typedef struct {  int ore;  int min;  int sec;  int cent; } Tempo;
typedef struct Elem { int    concorrente;   Tempo  t_tappa;   struct Elem * next; } Arrivo;
typedef Arrivo * Tappa;
typedef struct Nodo { int concorrente; Tempo t_totale; struct Nodo *next; } Posizione;
typedef Posizione * Classifica;

Il dispositivo di cronometraggio genera la lista in ordine di arrivo
(e quindi anche in ordine crescente di tempo) aggiungendo
in coda nuovi elementi man mano che arrivano i concorrenti.
Si implementino, dopo averne definito precisamente i prototipi, le funzioni
… sum(Tempo t1, Tempo t2, …); restituisce il tempo somma t = t1 + t2
… cmp(Tempo t1, Tempo t2, …); restituisce 0 se t1=t2, un intero positivo se t1>t2,
negativo altrimenti
Suggerimento:
si implementino e utilizzino le due funzioni
long int TempoCent(Tempo t) e
Tempo CentTempo(long int t) per convertire un Tempo
in centesimi di secondo e viceversa.

*/


#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef struct {
	int ore;
	int min;
	int sec;
	int cent;
} Tempo;

typedef struct Elem {
	int    concorrente;
	Tempo  t_tappa;
	struct Elem* next;
} Arrivo;

typedef Arrivo* Tappa;

typedef struct Nodo {
	int concorrente;
	Tempo t_totale;
	struct Nodo* next;
} Posizione;

typedef Posizione* Classifica;


long int TempoCent(Tempo t) {
	long int tmp = t.cent + 100 * t.sec + (60 * 100) * t.min + (60 * 60 * 100) * t.ore;
	return tmp;
}

Tempo CentTempo(long int t) {
	Tempo tmp;
	tmp.ore = t / (60 * 60 * 100);      t = t % (60 * 60 * 100);
	tmp.min = t / (60 * 100);      t = t % (60 * 100);
	tmp.sec = t / 100;     tmp.cent = t % 100;
	return tmp;
}

Tempo sum(Tempo t1, Tempo t2) {
	return CentTempo(TempoCent(t1) + TempoCent(t2));
}

long int cmp(Tempo t1, Tempo t2) {
	long int tmp1 = TempoCent(t1);
	long int tmp2 = TempoCent(t2);
	return tmp1 - tmp2;
}


/*
Supponendo di disporre di:
(1) le funzioni di ordinamento Tappa ordTappaM( Tappa t ) e
Classifica ordClassM( Classifica c ), che ordinano le liste
t e c in ordine crescente di numero di maglia;

(2) la funzione Classifica ordClassT( Classifica c ),
che restituisce c ordinata in base al tempo totale crescente (campo t_totale);

(3) le funzioni definite al punto (a),

si progetti la funzione … aggiorna(…) che aggiorna la classifica generale operando come segue:
riceve come parametri la lista con gli arrivi dell’ultima tappa,
così come è generata dal dispositivo di cronometraggio,
e la lista che rappresenta la classifica generale;
aggiunge al tempo totale di ogni concorrente il tempo conseguito nell’ultima tappa;
elimina dalla classifica generale, deallocandoli,
gli eventuali concorrenti non arrivati in fondo alla tappa (ritirati),
agendo direttamente sulla lista originale (si perdono, quindi, i loro dati);
riordina la classifica generale in base ai nuovi tempi totali.

Si definisca precisamente la funzione
Classifica aggiorna( Tappa t, Classifica c )
Suggerimento: conviene ordinare le liste in base allo stesso
criterio per poi scandirle in parallelo.

*/

Tappa ordTappaM(Tappa t);
Classifica ordClassM(Classifica c);
Classifica ordClassT(Classifica c);

Classifica aggiorna(Tappa t, Classifica c) {
	Classifica cur, prev, tmp;

	t = ordTappaM(t);     // 3 5 6 7 8 10
	c = ordClassM(c);	  // 3 4 5 6 7 8 9 10 11
	cur = c;
	prev = NULL;

	while (c->concorrente < t->concorrente) { //elimino chi non è arrivato
		c = (c)->next;
		free(cur);
		cur = c;
	}
	//								   t
	// 3		5		6 7 8		10| 
	// 3		5		6 7 8		10|		11 12
	// c							prev	   cur

	while (cur != NULL && t!=NULL) {
		if (cur->concorrente > t->concorrente) //maglia non presente in classifica
		{ 	// 3 5 6 7 8 10
			// 4 5 6 7 8 9 10 11
			printf("Errore");
			exit(-1);
		}
		
		if (cur->concorrente == t->concorrente) {
			cur->t_totale = sum(cur->t_totale, t->t_tappa);
			prev = cur;
			cur = cur->next;
			t = t->next;
		}
		else { /* dealloco il nodo se il conc. non è arrivato  */
			tmp = cur;
			cur = cur->next;
			free(tmp);
			prev->next = cur;
		}

	}

	while (cur != NULL) {/* dealloco gli eventuali ultimi non arrivati   */
		tmp = cur;
		cur = cur->next;
		free(tmp);
	}

	prev->next = NULL;

	c = ordClassT(c);  /* La classifica è riordinata per tempo totale  */
	return c;
}


void spampaClassifica(Classifica c) {
	if (c == NULL) return;

	printf("%d",c->concorrente);
	spampaClassifica(c->next);
}

Classifica ultimoInClassifica(Classifica c) {
	if (c->next == NULL) return c;

	return ultimoInClassifica(c->next);
}

//Classifica cancellaElemento(Classifica prev, Classifica daCancellare) {
//	Classifica tmp;
//	tmp = daCancellare;
//	daCancellare = daCancellare->next;
//	free(tmp);
//	prev->next = daCancellare;
//}
//
//Classifica cancellaElemento(Classifica prev) {
//	Classifica tmp, daCancellare = prev->next;
//	tmp = daCancellare;
//	daCancellare = daCancellare->next;
//	free(tmp);
//	prev->next = daCancellare;
//}