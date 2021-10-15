/*
Si disegnino lo stack dei record di attivazione e la memoria
allocata dal programma nello heap nell’istante in cui la
funzione f() inizia a eseguire l’istruzione indicata dalla freccia. 
Si rappresentino tutte le variabili (vettori: blocchi contigui;
puntatori: frecce; valori indefiniti: punti interrogativi)
Si calcoli la dimensione in byte della memoria allocata 
sullo stack (var. statiche e automatiche, tralasciando gli
indirizzi di ritorno) e di quella allocata nello 
heap (sizeof(int)=sizeof(void*)=4)
Si indichi la linea stampata dal programma sullo standard output

*/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef struct n { char c[8]; struct n *next; } nodo;

nodo * f(nodo * x, char * s) {
	nodo * n;
	if (strlen(s) > 0) {
		n = (nodo *)malloc(sizeof(nodo));
		n->next = x;
		strcpy(n->c, s++);
		n->c[1] = '\0';
		*(n->c) += strlen(s);
		return f(n, s);
	}
	return x;
}

void printr(nodo * r) {
	if (r) {
		printf("%s", r->c);
		printr(r->next);
	}
}

int main() {
	char p[] = "AMNG";
	printr(f(NULL, p));
	return 0;
}


















/*
Heap: 4 x sizeof(nodo) = 4 x (8+4) Byte = 48 Byte
Stack = sizeof(p) + sizeof(r) + 5 x sizeof( r.d.a. di f) = 5 Byte + 4 Byte + 5 x (4+4+4) Byte = 69 Byte

*/