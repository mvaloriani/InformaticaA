//Scrivere un programma che svolga le seguenti operazioni: 
// 1) Acquisisca informazioni relative a caratteristiche fisiche di 10 persone. 
//    Ogni informazione è composta da peso, altezza ed età. 
// 2) Terminata la fase di acquisizione, stampi sullo schermo le informazioni relative
//   a tutte le persone per le quali il valore dell'età è <= 20. 

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define MAX_PERS 3 
#define MAX_ETA 20 

typedef struct { 
	int peso;
	int alt;
	int eta; } dati; 

	int main() {

		dati arch[MAX_PERS]; 
		int i; 

		// acquisizione
		for(i=0;i<MAX_PERS;i++)  { 
			printf("Altezza: "); scanf("%d", &(arch[i].alt)); 
			printf("\nPeso: "); scanf("%d", &(arch[i].peso)); 
			printf("\nEta': "); scanf("%d", &(arch[i].eta));
		}



		// stapa persone con età<=max
		printf("\n persone con eta' <= %d", MAX_ETA);
		for (i=0; i<MAX_PERS; i++) {
			if(arch[i].eta <= MAX_ETA) {
				printf("\n %d, %d, %d", arch[i].alt,arch[i].peso,arch[i].eta);  
			}
		}

		system("pause"); 

		return 0;
	} 
