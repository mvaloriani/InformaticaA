/*
L’albero della cuccagna è un albero binario definito come segue (pieno di premi, descritti da una stringa):
*/
typedef struct nd {
	char premio[30];
	struct nd* sx, * dx;
} Nodo;
typedef Nodo* Albero;
/*
Si gioca per vincere un premio, che si trova in questo modo:
il giocatore, ricevuta una stringa formata solo da ‘S’ e da ‘D’,
parte dalla radice dell’albero, leggendo la stringa: ad ogni carattere 'S'
corrisponde uno spostamento nel ramo di sinistra, ad ogni 'D' uno a destra,
e vince il premio raggiunto utilizzando tutti i caratteri della stringa.
Se nel corso della ricerca la stringa suggerisce uno spostamento verso un ramo inesistente, si "cade".
Si codifichi in C una funzione void arrampica( Albero t, char * codice )
che stampa il premio vinto, oppure il messaggio "Non hai vinto" se il codice porta a una posizione non valida.

*/


#include <stdio.h> 
#include <string.h>
#include <stdlib.h>


void arrampica(Albero t, char* codice) {
	int len = strlen(codice);
	int count = 0;

	if (t == NULL) {
		printf("Sei Caduto");
		return;
	}

	if (len == 0) {
		printf(" % s", t->premio);
		return;
	}

	if (codice[0] == 'S')
		arrampica(t->sx, &codice[1]);
	else
		arrampica(t->dx, &codice[1]);

}
