#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/* Esercizio (tde 18-9-2006)

Scrivere un programma C che legge un vettore di 100 elementi
e stampa 1 se l’insieme rappresentato contiene tutti i numeri
di un intervallo senza duplicati, senza omissioni,
e 0 altrimenti.

Ad esempio la proprietà sussiste per gli insiemi 
{4, 6, 5} e {-2, 0, 1, -3, -1},
ma non per {0, 3, -1, 1} 
(dove evidentemente manca il numero 2).


*/


#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

#define n 100

int main()
{
	int v[n], i, k, min, max, trovato, duplicato, res;

	printf("Inserire un vettore di interi di dimensione %d\n", n);
	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);

	min = max = v[0];

	// cerco il minimo e il massimo
	for (i = 1; i < n; i++) {
		if (min > v[i])
			min = v[i];
		if (max < v[i])
			max = v[i];
	}

	res = 1;
	for (k = min; k <= max && res==1; k++) {
		trovato = 0;
		duplicato = 0;

		for (i = 0; i < n; i++) {
			if (v[i] == k) {
				if (trovato == 0) {
					trovato = 1;
				}
				else
				{
					duplicato = 1;
				}
			}
		}

		if (trovato == 0 || duplicato == 1)
			res = 0;
	}

	printf("%d\n", res);


	printf("\n\n");
	system("pause");
	return 0;
}

