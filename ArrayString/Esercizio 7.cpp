#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Scrivere  un  programma  C  che  legge  da  tastiera
una  sequenza  di  numeri  reali diversi da zero

La lettura termina quando la somma dei numeri immessi
è maggiore di 50, e comunque non si possono immettere più di 100 numeri.

Dopo avere letto tutti i numeri, se l’utente ha inserito almeno
3  valori, cercare  se  esiste  una  coppia  di  numeri
tali  che  il  loro  rapporto (o  il  suo inverso) 
sia uguale al primo numero immesso e, se esiste, stamparla.


Inserisci numero: 6.25
Inserisci numero: -2.5
Inserisci numero: 20
Inserisci numero: 13.863
Inserisci numero: -15.625
Inserisci numero: 4
Inserisci numero: 38.192

Il rapporto (o il suo inverso) tra -2.5 e -15.625 vale 6.25.

*/


#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

#define MAXDIM 100
#define MAXSUM 50
#define TOL 0.00000001 


int main()
{
	float dati[MAXDIM], sum = 0, rapp, inv_rapp;
	int i, j, trovata, n_dati = 0;
	

	do {
		// leggo un numero "diverso da zero" con una certa tolleranza
		do {
			printf("Inserisci numero: ");
			scanf("%f", &dati[n_dati]);
		} while (dati[n_dati] < TOL && dati[n_dati] > -TOL);
		
		sum = sum + dati[n_dati];
		n_dati++;
		// continuo fino a quando la somma non supera la soglia o raggiungo il numero massimo di elementi
	} while (sum <= MAXSUM && n_dati < MAXDIM);



	if (n_dati < 3) {
		printf("Sono stati inseriti solo %d elementi\n", n_dati);
	}


	else {
		trovata = 0;
		i = 1;
		while (!trovata && i < n_dati - 1) {

			j = i + 1;
			while (!trovata && j < n_dati) {

				rapp = dati[i] / dati[j];
				inv_rapp = dati[j] / dati[i];

				if (rapp - dati[0] < TOL && rapp - dati[0] > -TOL ||
					inv_rapp - dati[0] < TOL && inv_rapp - dati[0] > -TOL) {
					trovata = 1;
					printf("Il rapporto(o il suo inverso) tra %f e %f e’ %f\n", dati[i], dati[j], dati[0]);
				}
				j++;
			}
			i++;
		}

	}


	printf("\n\n");
	system("pause");
	return 0;
}

