#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Si scriva un programma in linguaggio C
che letto un numero intero positivo dallo standard input,
visualizzi a terminale il quadrato del numero
stesso facendo uso soltanto di operazioni di somma.
Si osservi che il quadrato di ogni numero intero
positivo N può essere costruito sommando tra loro i
primi N numeri dispari.
Esempio: N = 5;  N2 = 1 + 3 + 5 + 7 + 9 = 25.


*/

#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

int main() {

	int i, N, S = 0;
	do { /* Finché il numero inserito N non è positivo ripetere */
		printf("\n Inserisci un numero positivo N: ");
		scanf("%d", &N);
	} while (N <= 0);

	i = 0;
	while (i < N) {
		S = S + (i + i + 1);
		i++;
	}

	////Varianti
	//i = 1;
	//while (i <= N) {
	//	S = S + (i + i - 1);
	//	i++;
	//}

	////oppure
	//i = 1;
	//while (i < N) {
	//	if (i % 2 != 0)
	//		S = S + (i);
	//	i++;
	//}

	////oppure
	//i = 1;
	//while (i < N + N) {
	//	S = S + i;
	//	i = i + 2;
	//}

	////oppure
	//for (i = 1; i < 2*N; i=i+2)
	//{
	//	S = S + i;
	//}


	printf("Il quadrato del numero inserito e': %d \n", S);
	system("pause");
	return 0;
}
