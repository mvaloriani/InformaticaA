/*sercizio  5  (12 punti)
Si scriva un sottoprogramma che ricevuto in ingresso una lista L di float
ed un valore intero N, ed un valore intero X, stampa a video i valori che
costituiscono gli X massimi valori contenuti nella lista L in ordine decrescente.

Ad esempio, se il sottoprogramma riceve in ingresso la lista seguente ed il valore X = 3

10 2 3 23 101

verranno stampati i valori

101 23 10
*/



#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef struct Node { float data; struct Node* next; } Nodo;
typedef Nodo* Lista;

void stampaMax(Lista A, int x) {

	bubbleSort(A);
	int i = 0;

	while (i < x || A != NULL)
	{
		printf("%d \n", A->data);
		i++;
		A = A->next;
	}
}


/* Bubble sort the given linked list */
void bubbleSort(Node* start)
{
	int swapped, i;
	struct Node* ptr1;
	struct Node* lptr = NULL;

	/* Checking for empty list */
	if (start == NULL)
		return;

	do {
		swapped = 0;
		ptr1 = start;

		while (ptr1->next != lptr) {
			if (ptr1->data < ptr1->next->data)
			{
				swap(ptr1, ptr1->next);
				swapped = 1;
			}
			ptr1 = ptr1->next;
		}
		lptr = ptr1;
	} while (swapped);
	//} while (lptr!=start);
}

/* function to swap data of two nodes a and b*/
void swap(Node* a, Node* b)
{
	float temp = a->data;
	a->data = b->data;
	b->data = temp;
}