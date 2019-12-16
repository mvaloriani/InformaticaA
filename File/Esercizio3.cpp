#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Scrivere un programma in linguaggio C che:
definisce due vettori P e D contenenti ciascuno 100 numeri interi;

legge da standard input una sequenza di numeri interi ed inserisce
i valori pari nel vettore P e i valori dispari nel vettore D,
l’operazione di lettura termina quando almeno uno dei due vettori è stato riempito;
inserisce in un file di testo denominato dati.txt i valori contenuti
in P e D in modo alternato.

*/


#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

#define N 100


int main()
{
	int P[N], D[N], i = 0, j = 0, temp, max, k = 0;
	FILE* fp;

	do {
		scanf("%d", &temp);
		if (temp % 2 == 0) {
			P[i] = temp; i++;
		}
		else {
			D[j] = temp; j++;
		}
	} while (i < N && j < N);

	max = i > j ? i : j;
	//if (i > j) {
	//	max = i;
	//}
	//else {
	//	max = j;
	//}

	fp = fopen("dati.txt", "w");
	for (k = 0; k < max; k++) {
		if (k < i)
			fprintf(fp, "%d\n", P[k]);
		if (k < j)
			fprintf(fp, "%d\n", D[k]);
	}

	/* soluzione alternativa
	for (k = 0; k < min; k++) {
		fprintf(fp, "%d\n", P[k]);
		fprintf(fp, "%d\n", D[k]);
	}
	if (i > min) {
		for (k = min; k < i; k++) {
			fprintf(fp, "%d\n", P[k]);			
		}
	}
	else
	{
		for (k = min; k < j; k++) {
			fprintf(fp, "%d\n", D[k]);
		}
	}
	*/
	fclose(fp);


	system("pause");

	return 0;
}

