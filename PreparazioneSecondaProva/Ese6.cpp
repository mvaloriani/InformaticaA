#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
Un albero ternario è una struttura dati ricorsiva in cui ogni nodo
ha esattamente tre sotto-alberi.
(a)	Si proponga la definizione in C di un tipo di dato ricorsivo
che definisca
un albero ternario in cui ogni nodo, oltre ai sottoalberi,
contenga anche due
puntatori a carattere e due interi,
che rappresentino due parole p1 e p2 e due numeri
di pagina n1 e n2 (le pagine in cui p1 e p2 rispettivamente
compaiono per la prima volta nello stesso libro dell’esercizio 5).

*/

typedef struct Gemma {
	char * parola1, *parola2;
	int pagina1, pagina2;

	struct Gemma * left, *center, *right;
}Nodo;
typedef Nodo * Albero;


//Si codifichi la funzione ricorsiva di prototipo
//int trovaPagina(Albero a, char * lemma);
//che restituisce la pagina relativa alla parola lemma
//se questa è nell’indice, oppure –1 se non è nell’indice,
//badando ad attraversare in entrambi i casi solo la porzione
//necessaria dell'albero.



int trovaPagina(Albero a, char * lemma) {
	if (a == NULL)
		return -1;
	// lemma più piccolo di parola1
	if (strcmp(a->parola1, lemma) > 0)    /// lemma="casa"    parola1 = "dado"  parola2="pc"
		return trovaPagina(a->left, lemma);
	//lemma = parola1
	if (strcmp(a->parola1, lemma) == 0)
		return a->pagina1;
	// lemma compresa tra parola 1 e parola 2
	if (strcmp(a->parola2, lemma) > 0)
		return trovaPagina(a->center, lemma);
	//lemma = parola2
	if (strcmp(a->parola2, lemma) == 0)
		return a->pagina2;
	
	// lemma più grande di parola2
	return trovaPagina(a->right, lemma);	`
}

/*
Caso peggiore albero =  log3 N
(profondità albero, se l’albero è pieno ad ogni livello = pieno e bilanciato)
Caso medio = è ragionevole ritenere che la profondità massima cresca
logaritmicamente con N
(è vero se la “larghezza” dei livelli cresce al crescere della profondità).

Caso peggiore lista =  N
Caso “medio” = richiede N/2 accessi

Il rapporto (N/2)/(log N) diverge al crescere di N.

Questo vantaggio si paga però con una maggiore complessità
delle operazioni di inserimento
e cancellazione dei nodi, se si vuole garantire che esse lascino
l’albero su cui agiscono
ordinato e bilanciato [il che può richiedere pesanti ristrutturazioni].

*/


/*Si dia una definizione ricorsiva precisa (e/o la si codifichi in C)
della funzione pb(...)
che restituisce 1 se l’albero passato come parametro è pieno
e bilanciato, zero altrimenti.
*/

int pb(Albero a, int * livello) {
	int lr, lc, ll;					/* Il livello dei 3 sottoalberi    */
	if (a == NULL) {                  /* Un albero vuoto...              */
		*livello = 0;                     /*    ...ha profondità 0...        */
		return 1;                         /*    ...ma è pb!                  */
	}
	else if (
		pb(a->left, &ll) &&       /* Se i tre sottoalberi sono...    */
		pb(a->center, &lc) &&     /*    ...tutti pb e le loro...     */
		pb(a->right, &lr) &&      /*    ... profondità restituite    */
		ll == lc && lc == lr) {  /*    ...sono tutte uguali         */
		*livello = lr + 1;           /* [o lc o ll...tanto sono uguali] */
		return 1;                    /*    ...allora è pb!              */
	}
	return 0;                           /*   ...altrimenti no.             */
}
