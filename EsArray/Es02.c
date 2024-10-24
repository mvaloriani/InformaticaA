#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

//Scrivere un programma in C che legge un vettore 
// di interi di dimensione fissata, inverte il 
// vettore e lo stampa.





#include <stdio.h> 

#define LUNG 5 
int main() {
	int vett[LUNG], i, temp;

	Soluzione 1
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

	////Alternativa 1
	//for (i = 0; i < LUNG; i++)
	//	scanf("%d", &vett[LUNG - 1 - i]);
	//
	
	//Alternativa 2
	for (i = LUNG -1; i >= 0; i--)
		scanf("%d", &vett[i]);


	/* Stampa il vettore, che ora e' invertito */
	for (i = 0; i < LUNG; i++)
		printf("%d %d\n", i, vett[i]);
	
	system("pause");
	return 0;
}
