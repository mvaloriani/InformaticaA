/*
Due parole p e q si definiscono Hertzianamente compatibili (p  q)
se entrambe sono leggibili anche “oscillando” e leggendo alternativamente
i caratteri dell’una e dell’altra. La figura mostra che tigre  fiera e fiera  fresa.
In figura parole uguali sono tracciate da linee di ugual stile.
Si noti però che tigre /  fresa. Infatti  è (banalmente) simmetrica e riflessiva,
ma non transitiva. Si noti anche che la relazione sussiste in due modi (diretto o inverso).
In figura: fiera e tigre si leggono iniziando dalla stessa lettera (modo diretto), per fiera
e fresa occorre iniziare dall’iniziale dell’ “altra” parola nella coppia (modo inverso). 
Se la relazione fosse definita solo in modo diretto o solo in modo inverso varrebbe anche
la proprietà transitiva (esempio: aria, prua, erba, orma sono tutte direttamente 
compatibili tra loro), ma consideriamo due parole compatibili indipendentemente dal modo in
cui la proprietà si manifesta.

*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// (a)	Si codifichi in C la funzione ...hercom(...) che verifica la compatibilità Hertziana di due stringhe

int hercom( char * a, char * b ) {
	int i, dir = 1, inv = 1, lun = strlen(a);

	// verifico la lunghezza
	if( lun != strlen(b) )
		return 0;

	// confronto le lettere pari o dispari
	for( i=0; i<lun-1; i+=2 ) {
		// confronto lettere dispari
		if( a[i] != b[i] ) inv = 0;
		//confronto lettere pari
		if( a[i+1] != b[i+1] ) dir = 0;
	}
	return dir || inv;
}

/*(b)	Si codifichi in C la funzione ...hercomlen(...) che restituisce la lunghezza
della massima “catena” di coppie consecutive di parole hertzianamente compatibili in
una lista (definita come segue). */

typedef struct lp { char  * word; struct lp * next; } nodo;
typedef nodo* List;

int hercomlen( List lista ) {
	int maxlen = 0, curlen = 0;
	// scorro la lista dinamica fino alla fine
	while( lista != NULL && lista->next != NULL ) {
		//controllo se le parole sono compatibili
		if( hercom( lista->word, lista->next->word ) ) {
			//incremento la linghezza attuale
			++curlen;
			// verifico se ho superato il massimo
			if( curlen > maxlen ) maxlen = curlen; 
		}
		else
			//azzero la lunghezza
			curlen = 0;
		//avanzo la lista
		lista = lista->next;
	}
	return maxlen;
}


/* (c)	Un albero di parole (definito come segue) si dice Hertzianamente percorribile
se tutti i cammini che dalla radice portano alle foglie rappresentano sequenze di
coppie di parole Herzianamente compatibili. Si codifichi la funzione ...hertree(...)
che verifica se un albero gode della proprietà */

typedef struct ap { 	char  * word;  	struct ap * left;	struct ap * right; } nodoAlbero;
typedef nodoAlbero * tree;

/* Casi positivi
- è vuoto (primo caso base) oppure 
- è costituito da un solo nodo (secondo caso base), oppure
- i suoi sottoalberi dx e sx sono entrambi HP (ipotesi induttiva) e inoltre la parola 
contenuta nella sua radice è compatibile con le parole contenute nelle radici dei
suoi sottoalberi (se non degeneri)
*/

int hertree( tree t ) {
	//albero vuoto
	if( t == NULL ) return 1;
	// albero conun solo nodo
	if( t->left == NULL && t->right == NULL ) return 1;
	// valuto il ramo di sinistra
	if( t->left  != NULL && ! hercom(t->word,t->left->word) ) return 0; 
	// valuto il ramo di destra 
	if( t->right != NULL && ! hercom(t->word,t->right->word) ) return 0;
	// valuto ricorsivamente l'albero di sinistra
	if( ! hertree( t->left ) ) return 0;
	// valuto ricorsivamente l'albero di destra
	if (!hertree(t->right)) return 0;
	// valuto ricorsivamente l'albero di destra
	return 1;
}



/*
(d)	In una lista, parole compatibili possono trovarsi anche distanti tra loro.
Si può però provare, con una scansione della lista, a costruire un albero binario Hertzianamente
percorribile:
si inizia ponendo nella radice la prima parola della lista e si prosegue “appendendo” le parole che
si incontrano via via nella lista a un qualsiasi nodo dell’abero che non abbia già due figli 
e che contenga una parola compatibile. Si codifichi in C una funzione ...build(...) 
che riceve una lista di parole, prova a costruire un albero Hertzianamente percorribile con una sola 
scansione lineare della lista, e se riesce a collocare tutte le parole della lista restituisce l’albero costruito,
altrimenti (se si trova una parola “non collocabile”) restituisce NULL e dealloca l’albero già costruito.
*/

tree buildNode(char* word){
	if (word!=NULL){
		tree radice;
		radice = (tree)malloc(sizeof(nodoAlbero));
		radice->word=word;	
		return radice;
	}
	return NULL;
}

bool insert(tree t, char* word){
	// radice e parola non nulle
	if (t== NULL || word==NULL)
		return false;
	// ho figli? (sono una foglia?)
	if (t->left==NULL && t->right==NULL){
		// provo a inserire la parola
		if(hercom(t->word, word)){
			//per convenzione inserisco a sinistra
			t->left= buildNode(word);
			return true;
		}
		return false;
	}
	// ho dei figli
	else
	{// provo a inserire a sinistra
		if(insert(t->left, word)==false){
			// non sono riuscito a insrire a sinistra provo a destra
			if (insert(t->right, word) == false){
				// non sono riuscito a inserire neanche a destra
				return false;
			}			
		}	
		return true;
	}
}

void destroyTree(tree radice){
	if(radice!=NULL){
		if (radice->left!=NULL)	{
			destroyTree(radice->left);
			radice->left=NULL;
		}
		if (radice->right!=NULL){
			destroyTree(radice->right);
			radice->right=NULL;
		}
		free(radice);
	}
}

tree buildTree(List lista){

	if (lista!=NULL){
		tree radice=buildNode(lista->word);	
		lista = lista->next;

		//scandisco la lista
		while( lista != NULL){
			if(insert(radice,lista->word)==false){
				destroyTree(radice);
				return NULL;
			}
			lista = lista->next;
		}
		return radice;
	}
	return NULL;
}

