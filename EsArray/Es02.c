//Scrivere un programma in C che legge un vettore 
// di interi di dimensione fissata, inverte il vettore e lo stampa.


#include <stdio.h> 

#define LUNG 5 
int main() {
	int vett[LUNG], i, temp; 
	
	/*usata per scambiare due elementi del vettore */
	printf("Inserire un vettore di interi di dimensione %d\n", LUNG);
	for (i = 0; i < LUNG; i++)
		scanf("%d", &vett[i]);
	


	/* Inverti il vettore senza l'utilizzo di un vettore ausiliario */
	for (i = 0; i < LUNG / 2; i++) {
		temp = vett[i];
		vett[i] = vett[LUNG - 1 - i];
		vett[LUNG - 1 - i] = temp;
	}
	/* Stampa il vettore, che ora e' invertito */
	for (i = 0; i < LUNG; i++)
		printf("%d %d\n", i, vett[i]); 
			return 0;
}
