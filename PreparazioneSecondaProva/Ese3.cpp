/*
La funzione … toro( … ) riceve come parametro un vettore di interi
e la specifica della sua dimensione, e alloca e restituisce
una lista dinamica "circolare" di interi che contiene 
solo i valori del vettore positivi e 
divisibili per 11.
Ovviamente la lista può essere circolare solo se non è vuota, 
quindi si suggerisce di renderla
circolare solo alla fine dell'analisi del vettore 
[N.B. una lista è circolare se l'ultimo elemento
invece di avere un puntatore a NULL ha un puntatore alla testa].
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>


//(a)	Si definiscano in C la struttura della lista e il prototipo della funzione toro. 
//(b)	Si codifichi in C la funzione (unitamente alle eventuali funzioni di supporto).

typedef struct lp { int  dato; struct lp * next; } Nodo;
typedef Nodo* List;

List buildNode(int word){

	List lista;
	lista = (List)malloc(sizeof(Nodo));
	lista->dato=word;	

	return lista;
}

List toro(int* vet , int dim){ //int vet[] ok //int vet[dim] errore
	List first=NULL;
	List temp=NULL;

	for (int i = 0; i < dim; i++)	{
		if (vet[i]%11==0 && vet[i]>=0)		{
			//primo elemento trovato
			if (first==NULL)			{
				first=buildNode(vet[i]);
				temp=first;			}
			else			{
				// aggiungo gli elementi successivi
				temp->next=buildNode(vet[i]);
				temp=temp->next;			}
		}
	}
	temp->next=first;
	return first;
}

void toro2(int* vet, int dim, List* first) {
	
	List prec = NULL;

	for (int i = 0; i < dim; i++)
	{
		if (vet[i] % 11 == 0)
		{
			//primo elemento trovato
			if ((*first) == NULL)
			{
				(*first) = buildNode(vet[i]);
				prec = *first;
			}
			else
			{
				// aggiungo gli elementi successivi
				prec->next = buildNode(vet[i]);
				prec = prec->next;
			}
		}

	}

	prec->next = *first;
}

int main(){

	int vet[10];
	for (int i = 0; i < 10; i++)
	{
		vet[i]=11*i;
	}

	List lista=toro(vet, 10);

	List lista2 = NULL;
	toro2(vet, 10, &lista2);

	for (int i = 0; i < 12; i++)
	{
		printf("indice %d valore %d puntatore next %p \n", i, lista->dato, lista->next);
		lista=lista->next;

	}
	system("pause");

}