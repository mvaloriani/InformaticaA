/*
Si consideri una lista di contatti telefonici così definita

typedef struct c { char c;
				struct c * next; } Cifra;

typedef Cifra * NumTelefono;

typedef struct con { char nome[1000];
					char indirizzo[1000];
					NumTelefono numero;
					struct con * next; } Contatto;

typedef Contatto * Rubrica;

Si noti che ogni nodo contiene un nome e un numero costruito come una
lista di caratteri (ogni carattere è una cifra del numero).

Si codifichi una funzione stampaContatti che stampa la lista dei contatti col loro numero.

Si codifichi poi in C una funzione correggiContatti che riceve una
lista di Contatti definiti come sopra. La funzione controlla e modifica
i numeri di telefono in base alle regole riportate sotto.
- Se il numero inizia con il carattere '+' resta inalterato
- Se inizia con due zeri, li sostituisce con un '+'
- Se inizia con un solo zero o con una cifra diversa da zero ('1','2', ... '9') 
vi aggiunge i caratteri ‘+’, ‘3’ e ‘9’ all'inizio

Si sviluppino le funzioni richieste e le si invochi nel main sotto definito.


OUTPUT ATTESO:
Alessandro: via Milano 1,Mi Num.333333333
Marco: via Milano 1,Mi Num.+3956789
Giacomo: via Milano 1,Mi Num.003956565656
Giovanni: via Milano 1,Mi Num.03456678
Matteo: via Milano 1,Mi Num.4444444

Alessandro: via Milano 1,Mi Num.+39333333333
Marco: via Milano 1,Mi Num.+3956789
Giacomo: via Milano 1,Mi Num.+3956565656
Giovanni: via Milano 1,Mi Num.+3903456678
Matteo: via Milano 1,Mi Num.+394444444

*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct c {
	char c;
	struct c* next;
} Cifra;
typedef Cifra* NumTelefono;

typedef struct con {
	char nome[1000];
	char indirizzo[1000];
	NumTelefono numero;
	struct con* next;
} Contatto;
typedef Contatto* Rubrica;

NumTelefono InsInTestaCifra(NumTelefono lista, char elem);
NumTelefono InsInFondoCifra(NumTelefono lista, char elem);
Rubrica costruisciRubrica();
NumTelefono costruisciNumero(char* telefono);
Rubrica InsInFondoContatto(Rubrica lista, char* nome, char* indirizzo, char* telefono);

void StampaContatti(Rubrica r);
void correggiContatti(Rubrica r);
NumTelefono correggiNumero(NumTelefono num);


int main() {
	Rubrica rub;
	rub = costruisciRubrica();

	// TODO: stampa rubrica
	StampaContatti(rub);

	// TODO: correggi rubrica
	correggiContatti(rub);

	// TODO: stampa rubrica corretta
	StampaContatti(rub);
}

/* stampa tutti i contatti con il loro numero */
void stampaContatti(Rubrica rub) {
	Rubrica p = rub;
	while (p != NULL) {
		NumTelefono num = p->numero;
		printf("%s: %s Num.", p->nome, p->indirizzo);
		while (num != NULL) {
			printf("%c", num->c);
			num = num->next;
		}
		printf("\n");
		p = p->next;
	}
}

/* corregge tutti i numeri della rubrica */
void correggiContatti(Rubrica rub) {
	Rubrica p = rub;
	while (p != NULL) {
		p->numero = correggiNumero(p->numero);
		p = p->next;
	}
}

/* funzione di supporto che corregge un singolo numero di telefono */
NumTelefono correggiNumero(NumTelefono num) {
	NumTelefono nuovo, n3, n9;

	if (num == NULL)
		return num;

	/* caso 1: inizia con '+' -> non si modifica */
	if (num->c == '+')
		return num;

	/* caso 2: inizia con '00' -> sostituisco '00' con '+' */
	if (num->c == '0' && num->next != NULL && num->next->c == '0') {
		NumTelefono terzo = num->next->next;
		/* libero i due nodi '0' */
		free(num->next);
		free(num);
		/* creo nuovo nodo con '+' */
		nuovo = (NumTelefono)malloc(sizeof(Cifra));
		nuovo->c = '+';
		nuovo->next = terzo;
		return nuovo;
	}

	/* caso 3: inizia con '0' singolo oppure con cifra 1..9:
	   aggiungo in testa '+', '3', '9' */
	nuovo = (NumTelefono)malloc(sizeof(Cifra));
	n3 = (NumTelefono)malloc(sizeof(Cifra));
	n9 = (NumTelefono)malloc(sizeof(Cifra));

	nuovo->c = '+';
	n3->c = '3';
	n9->c = '9';

	nuovo->next = n3;
	n3->next = n9;
	n9->next = num;

	return nuovo;
}



Rubrica costruisciRubrica() {
	Rubrica lis = NULL;
	int i = 0;
	char nomi[5][20] = { "Alessandro","Marco","Giacomo","Giovanni","Matteo" };
	char indirizzi[5][20] = { "via Milano 1,Mi","via Milano 1,Mi","via Milano 1,Mi","via Milano 1,Mi","via Milano 1,Mi" };
	char telefoni[5][20] = { "333333333","+3956789","003956565656","03456678","4444444" };
	for (i = 0; i < 5; i++)
		lis = InsInFondoContatto(lis, nomi[i], indirizzi[i], telefoni[i]);
	return lis;
}

NumTelefono InsInTestaCifra(NumTelefono lista, char elem) {
	NumTelefono punt;
	punt = (NumTelefono)malloc(sizeof(Cifra));
	punt->c = elem;	punt->next = lista;
	return  punt;
}

NumTelefono InsInFondoCifra(NumTelefono lista, char elem) {
	NumTelefono punt;
	if (lista == NULL) {
		punt = (NumTelefono)malloc(sizeof(Cifra));
		punt->next = NULL; punt->c = elem;
		return  punt;
	}
	else {
		lista->next = InsInFondoCifra(lista->next, elem);
		return lista;
	}
}

NumTelefono costruisciNumero(char* telefono) {
	int i;
	NumTelefono lis = NULL;
	for (i = 0; telefono[i] != '\0'; i++)
		lis = InsInFondoCifra(lis, telefono[i]);
	return lis;
}

Rubrica InsInFondoContatto(Rubrica lista, char* nome, char* indirizzo, char* telefono) {
	Rubrica punt;
	if (lista == NULL) {
		punt = (Rubrica)malloc(sizeof(Contatto));
		punt->next = NULL;
		strcpy(punt->nome, nome);
		strcpy(punt->indirizzo, indirizzo);
		punt->numero = costruisciNumero(telefono);
		return  punt;
	}
	else {
		lista->next = InsInFondoContatto(lista->next, nome, indirizzo, telefono);
		return lista;
	}
}