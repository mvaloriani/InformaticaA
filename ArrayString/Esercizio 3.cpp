#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Scrivere un programma C che legge un vettore di lunghezza arbitraria 
e stampa 1 se il vettore contiene solo valori diversi, 0 altrimenti.

*/


#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

#define LUNG 5 

int main()
{
	int v[LUNG], i, j, res ; 

	printf("Inserire un vettore di interi di dimensione %d\n", LUNG);
	for (i = 0; i < LUNG; i++)
		scanf("%d", &v[i]);
	
	res = 1;
	for (i = 0; i < LUNG - 1; i++)
		for (j = i + 1; j < LUNG; j++)
			if (v[i] == v[j])
				res = 0;
	
	////soluzione 2
	//res = 1;
	//for (i = 0; i < LUNG - 1 && res == 1; i++)
	//	for (j = i + 1; j < LUNG; j++)
	//		if (v[i] == v[j])
	//			res = 0;
	
	//// Soluzione 3
	//res = 1;
	//for (i = 0; i < LUNG - 1; i++) {
	//	for (j = i + 1; j < LUNG; j++) {
	//		if (v[i] == v[j]) {
	//			res = 0;
	//			printf("\n %d \n", res);
	//			printf("\n");
	//			system("pause");
	//			return 0;
	//		}
	//	}
	//}

	printf("\n %d \n", res);


	printf("\n");
	system("pause");
	return 0;
}

