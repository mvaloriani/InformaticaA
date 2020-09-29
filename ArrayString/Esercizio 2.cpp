#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Scrivere un programma in C che legge un
vettore di interi di dimensione fissata, 
inverte il vettore e lo stampa.

*/


#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

#define LUNG 5 


int main()
{
	int vett[LUNG], i, temp; /*usata per scambiare due elementi del vettore */
	int inv[LUNG]; /*vettore ausiliario */

	printf("Inserire un vettore di interi di dimensione %d\n", LUNG);
	for (i = 0; i < LUNG; i++)
		scanf("%d", &vett[i]);

	/* Inverti il vettore con l'utilizzo di un vettore ausiliario */
	for (i = 0; i < LUNG ; i++) {
		inv[LUNG - 1 - i] = vett[i];
	}

	/* Stampa il vettore, che ora e' invertito */
	for (i = 0; i < LUNG; i++)
		printf("%d %d\n", i, inv[i]);

	// Soluzione alternativa
	//Inverti il vettore senza l'utilizzo di un vettore ausiliario 
	for (i = 0; i < LUNG / 2; i++) {
		temp = vett[i];
		vett[i] = vett[LUNG - 1 - i];
		vett[LUNG - 1 - i] = temp;
	}
	// Stampa il vettore, che ora e' invertito 
	for (i = 0; i < LUNG; i++)
		printf("%d %d\n", i, vett[i]); 
	

	printf("\n");
	system("pause");
	return 0;
}

