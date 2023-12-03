#include <stdio.h> 
#include <math.h>
#include <stdlib.h>


/*
Trovare con una funzione ricorsiva l’elemento massimo in una lista
 */

typedef struct Nodo {
	int valore;
	struct Nodo *prox;
} nodo;
typedef nodo *lista;


lista radice;
nodo* max(lista lis) {
	nodo * e;
	if (lis == NULL) {//può accadere solo 1° chiamata
		printf("lista vuota");
		exit(1);//termina l’esecuzione del programma
	}
	if (lis->prox == NULL)
		return lis;
	
	e = max(lis->prox);
	
	if (e->valore < lis->valore)
		return lis;
	else
		return e;
}

//int max2(Nodo * lis)
int max2(lista lis) {
	int tempMax;

	if (lis == NULL) {//può accadere solo 1° chiamata
		printf("lista vuota");
		exit(1);//termina l’esecuzione del programma
	}

	if (lis->prox == NULL)
		return lis->valore;

	tempMax = max2(lis->prox);
	if (tempMax < lis->valore)
		return lis->valore;
	else
		return tempMax;
}

