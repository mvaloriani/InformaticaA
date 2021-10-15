#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Scrivere i primi 30 elementi di una serie
così definita: i primi tre elementi valgono 1,
i successivi (i>=4) valgono la somma degli
elementi i-1 e i-3
1 1 1 2 3 4 6 9 13 19 28 41 60 …

*/

#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

int main() {

	int quanti = 30, i;
	int elem1 = 1, elem2 = 1, elem3 = 1, elem;
	printf("1 1 1");

	i = 4;
	while (i <= quanti) {
		elem = elem1 + elem3;
		printf(" %d", elem);
		elem3 = elem2;
		elem2 = elem1;
		elem1 = elem;
		i++;
	}
	printf("\n");

	elem1 = 1, elem2 = 1, elem3 = 1, elem;
	for (i = 0; i < quanti; i++)
	{
		if (i < 3) {
			printf("1 ");
			//continue;
			//break;
		}
		else {
			elem = elem1 + elem3;
			printf("%d ", elem);
			elem3 = elem2;
			elem2 = elem1;
			elem1 = elem;
		}
	}

	elem1 = 1, elem2 = 1, elem3 = 1, elem;
	i = 0;
	do
	{
		if (i < 3) {
			printf("1");
		}
		else {
			elem = elem1 + elem3;
			printf("%d ", elem);
			elem3 = elem2;
			elem2 = elem1;
			elem1 = elem;
		}
		i++;
	} while (i < quanti);


	printf("\n");
	system("pause");
	return 0;
}
