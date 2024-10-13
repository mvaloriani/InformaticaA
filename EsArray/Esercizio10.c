/*
Scrivere un programma C che legge da tastiera una sequenza di 100 numeri interi.
Dopo avere letto tutti i numeri cercare  le coppie di  numeri tali che il primo sia il doppio dell’altro.

Esempio
1 5 6 10 3 4 7 2 
stampa
6 3 / 10 5 / 4 2 / 2 1

*/

#include <stdio.h> 
#include<stdlib.h>

#define MAX_NUM 10 
int main() { 
	int dati[MAX_NUM]; 
	int i=0, j=0; 

	//leggo i numeri
	do { scanf("%d",&dati[i]); i++; } while(i<MAX_NUM);

	for (i=0; i<MAX_NUM; i++) 
		for(j=0;j<MAX_NUM;j++) { 
			if ((dati[j]==2*dati[i]) && i!=j) { 
				printf("\ncoppia: %d e %d",dati[i],dati[j]); 
				break;
			
			} 
		} 
	system("pause");
	return 0;
}
