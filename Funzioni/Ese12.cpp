/*
Sia dato un vettore di N ≥ 2 elementi. 
Ogni elemento del vettore è un numero intero.
Si chiede di progettare e codificare in C una funzione che
verifichi se, a partire da un elemento di indice i ≥ 0 fino
alla fine del vettore, ogni elemento abbia valore inferiore 
alla somma di tutti gli elementi collocati alla sua destra, 
cioè alla somma di tutti gli elementi aventi indice superiore
al suo (beninteso questa verifica non s'applica all'ultimo
elemento, che non ha niente alla sua destra).

Per esempio, il vettore seguente (con N = 5) soddisfa alla condizione in questione, a partire dall'elemento di indice 1 (ma non a partire da quello di indice 0).
	indice 0 1 2 3 4
	elemento 9 3 0 1 4

La funzione ha come argomento il vettore e l'indice i da cui partire 
con la verifica. Essa restituisce 1 se il vettore soddisfa alla 
condizione così descritta, 0 altrimenti.
Si supponga di disporre già di una funzione,
	int somma(int vett [], int k)
che restituisce la somma di tutti gli elementi del vettore vett,
a partire da quello di indice k (compreso) fino alla fine
del vettore (compresa).
*/

#include <stdio.h>
#define N 1000

int verifica_inf(int vett[], int i);
int somma(int vett[], int i);

int verifica_inf(int vett[], int i) {
	int j, flag = 1;
	j = i;

	while ((j <= N - 2) && (flag == 1)) {
		if (vett[j] < somma(vett, j + 1)) { j++; }
		else { flag = 0; }
	}
	return flag;
}

int verifica_inf2(int vett[], int i) {
	int j;
	j = i;

	while (j <= N - 2) {
		if (vett[j] < somma(vett, j + 1)) { j++; }
		else return 0;
	}
	return 1;
}


int somma(int vett[], int i) {
	int k, sum = 0;
	for (k = i; k < N; k++)
		sum = sum + vett[k];
	return sum;
}
