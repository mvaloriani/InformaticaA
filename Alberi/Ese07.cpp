/*
Si consideri la seguente definizione di un albero binario:
typedef struct Elemento { char parola[30];
int occorrenze;
struct Elemento * left, * right;  } Nodo;
typedef Nodo * Tree;

La seguente funzione inserisce nell'albero t tutte le
parole contenute nella lista l. L'indice deve contenere una sola
volta le parole del testo, ordinate alfabeticamente secondo il 
criterio per cui in ogni nodo n dell'albero tutte le parole del
sottoalbero destro precedono la parola di n, mentre quelle
del sottoalbero sinistro la seguono.

Tree creaIndice( ListaParole l ) {
Tree t = NULL;
while( l != NULL ) {
t = inserisciOrd( t, l->word );
list = list->next;
}
return t;
}
Si codifichi in C la funzione inserisciOrd, badando
ad allocare i nodi per le parole non presenti nell'indice e 
aumentare il contatore delle occorrenze per le parole già presenti.

*/


#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef struct Elemento {
	char parola[30];
	int occorrenze;
	struct Elemento * left, *right;
} Nodo;
typedef Nodo * Tree;

typedef struct Parola {
	char word[30];
	struct Parola * next;
};

typedef Parola * ListaParole;

Tree creaIndice(ListaParole l) {
	Tree t = NULL;
	while (l != NULL) {
		t = inserisciOrd(t, l->word);
		l = l->next;
	}

}


	Tree inserisciOrd(Tree t, char * p) {
		if (t == NULL) {
			t = (Tree)malloc(sizeof(Nodo));
			t->left = t->right = NULL;
			t->occorrenze = 1;
			strcpy(t->parola, p);
		}

		else if (strcmp(p, t->parola) == 0)
			t->occorrenze += 1;
		else if (strcmp(p, t->parola) < 0)
			t->left = inserisciOrd(t->left, p);
		else
			t->right = inserisciOrd(t->right, p);
		return t;
	}

	ListaParole crea(char * p) {

		ListaParole t = (ListaParole)malloc(sizeof(Parola));
		t->next = NULL;
		strcpy(t->word, p);
	}

	Tree insierisci(ListaParole l, char *p) {
		while (l != NULL) {
			l = l->next;
		}
		l->next = crea(p);

	}



