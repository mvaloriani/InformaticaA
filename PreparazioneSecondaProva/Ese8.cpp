#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento {
	char parola[30];
	int occorrenze;
	struct Elemento * left, * right;
} Nodo;

typedef Nodo * Tree;


/* La seguente funzione inserisce nell'albero indice, inizialmente vuoto, 
tutte le parole contenute nella lista testo. L'indice deve contenere una 
sola volta le parole del testo, ordinate alfabeticamente secondo il criterio
per cui in ogni nodo n dell'albero tutte le parole del sottoalbero destro 
precedono lessicograficamente la parola di n, mentre quelle del sottoalbero sinistro la seguono.
Tree creaIndice( ListaParole list ) {
Tree t = NULL;
while( list != NULL ) {
t = inserisciOrd( t, list->word );
list = list->next;
}
return t;

Si codifichi in C la funzione inserisciOrd, badando ad allocare
opportunamente i nodi per le parole non presenti nell'indice e incrementare
il contatore delle occorrenze per le parole già presenti.

casa
amore
dado
zio
armadio



*/





Tree inserisciOrd( Tree t, char * p )
{
	// Albero vuoto, creo la radice
	if( t == NULL ) {
		t = (Tree) malloc(sizeof(Nodo));
		t->left = t->right = NULL;
		t->occorrenze = 1;
		strcpy(t->parola, p);
	}
	//  parola trovata
	else if ( strcmp(p, t->parola)==0 )
		t->occorrenze += 1;
	// parola più piccola, cerco a sinistra
	else if ( strcmp(p, t->parola) < 0 )
		t->left = inserisciOrd( t->left, p );
	else
		// parola più piccola, cerco a destra
		t->right = inserisciOrd( t->right, p );
	return t;
}

// inserire in modo da creare un albero bilanciato sarebbe molto più complesso