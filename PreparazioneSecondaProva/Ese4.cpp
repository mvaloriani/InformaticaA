#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/*

Si codifichi in C la funzione … spargidivisori( … ), 
che riceve come parametri una lista di interi e 
una matrice NxN di interi,
tutti strettamente positivi. 
La funzione deve cercare di copiare ogni valore v
della lista nella matrice, inserendolo al posto di un valore 
che sia multiplo di v.
Se ci riesce, restituisce 1, e la matrice deve contenere tutti 
i valori modificati,
se non ci riesce, però, oltre a restituire 0, deve lasciare inalterata
la matrice.
Attenzione: 
(1) i valori v devono sempre essere confrontati con la 
versione iniziale della matrice,
non con le versioni "intermedie" derivanti dalla sostituzione di alcuni valori,
(2) se ci sono più multipli di v, se ne può sostituire uno a piacere 
(il primo che si incontra),
(3) si badi a definire chiaramente e/o dichiarare eventuali 
opportune strutture dati di appoggio
o funzioni ausiliarie.

*/

typedef struct Node { int dato; struct Node * next; } Nodo;
typedef Nodo * Lista;

Lista buildNode(int word){

	Lista lista;
	lista = (Lista)malloc(sizeof(Nodo));
	lista->dato=word;	

	return lista;
}

const int N=2;


bool insert(int mat[][N], int temp[][N], int v){
	for (int i = 0; i < N; i++)	{
		for (int j = 0; j < N; j++)	{
			//controllo se è un multiplo
			if(mat[i][j]%v==0){
				// inserisco nella matrice di supporto
				temp[i][j]=v;
				return true;
			}
		}
	}
	return false;
}

bool insert2(int mat[][N], int temp[][N], int temp2[][N], int v) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			//controllo se è un multiplo
			if (mat[i][j] % v == 0) {
				if (temp2[i][j] == 0) {
					// inserisco nella matrice di supporto
					temp[i][j] = v;
					temp2[i][j] = 1;

					return true;
				}
			}
		}
	}
	return false;
}

int spargidivisori(Lista lista, int mat[N][N]){

	// creo una matrice copia di supporto
	int temp[N][N];
	for (int i = 0; i < N; i++)	{
		for (int j = 0; j < N; j++)	{
			temp[i][j]=mat[i][j];
		}		
	}
	//// creo una secondamatrice copia di supporto
	int temp2[N][N];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			temp2[i][j] = 0;
		}
	}


	// provo a inserire tutti i valori della lista
	while (lista->next!=NULL)
	{
		//provo a inserire l'elemento
		if (!insert(mat, temp,lista->dato)){
			return 0;
		}

		lista=lista->next;
	}
	mat=temp;
	return 1;
}



/* Questa versione è molto inefficiente perchè duplica una matrice inutilmente e speca spazio
vediamo una versione alternativa
*/

typedef struct myNode { int dato; int j; int i; struct myNode * next; } myNodo;
typedef myNodo* myList;
myList buildMyNode(int word, int i, int j){

	myList lista;
	lista = (myList)malloc(sizeof(myNodo));
	lista->dato=word;	
	lista->i=i;
	lista->j=j;		
	return lista;
}

void deleteMyList(myList lista){
	if(lista!=NULL){
		deleteMyList(lista->next);
		free(lista);			
	}
}

myList test(int** mat, int dim, int v, mylist lista){

	for (int i = 0; i < dim; i++){
		for (int j = 0; j < dim; j++){
			if (mat[i][j]%v==0 && giaInseriti(lista,i,j)){
				return buildMyNode(v,i,j);
			}
		}
	}
	return NULL;
}

int giaInseriti(myList lista, int i, int j) {
	if (lista != NULL && lista->i == i && lista->j == j)
		return true;

	if (lista->next != NULL) {
		return giaInseriti(lista->next, i,j );
	}
	return false
}

int spargidivisori2(Lista lista, int** mat, int dim){

	myList testa=NULL;
	myList prec=NULL;


	// verico se i valori possono essere sostituiti nella matrice iniziale.

	while (lista->next!=NULL)
	{
		prec->next=test(mat, dim, lista->dato);
		//verifico se l'elemento è presente
		if (prec->next==NULL){
			deleteMyList(testa);
			return 0;
		}
		// se la prima volta aggiorno la testa della lista
		if (testa==NULL){
			testa=prec;
		}
		// avanzo le liste
		prec=prec->next;
		lista=lista->next;
	}

	// è possibile fare tutte le sostituzioni, procedo a modificare la matrice
	while (testa->next!=NULL)	{
		mat[testa->i][testa->j]=testa->dato;
		testa=testa->next;
	}

	deleteMyList(testa);

	return 1;
}

/*
Questa soluzione è preferibile finchè il numero di valori da sostituire è minore della metà degli elementi
*/

{

f(NULL, vet)

}

