/*
Scrivere un programma in C che legge un vettore 
di interi di dimensione fissata e ne stampa la somma
*/

#include <stdio.h> 
#define LUNG 5 
int main() { 
	int vett[LUNG],i,sum=0; 
	printf("Inserire un vettore di interi di dimensione %d\n", LUNG); 
	for (i = 0; i < LUNG; i++) 
		scanf("%d", &vett[i]); 

	/* Somma gli elementi del vettore */ 
	for (i = 0; i < LUNG; i++) { 
		sum=sum+vett[i];
	} 
	/* Stampa la somma */ 
	printf("Somma: %d\n", sum);

		return 0; 
}
