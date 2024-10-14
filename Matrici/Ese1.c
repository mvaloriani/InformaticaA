#include<stdio.h>
#include<stdlib.h>

/*
Scrivere un programma che chiede all’utente di riempire una matrice,
la stampa, cerca, se esiste, la prima posizione in cui appare lo 0,
l’ultima posizione in cui appare lo 0 e la posizione mediana in cui
appare lo 0 e dice in che posizione sono state trovate.
*/

#define N 3  
#define M 4 
int main() {
	int m[N][M], i, j, trovato, cont = 0, cont2 = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			printf("\nInserisci un elemento della matrice [%d][%d]: ", i, j);
			scanf("%d", &m[i][j]);
		}
	}
	printf("\nLa matrice inserita e': \n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			printf(" %d ", m[i][j]);
		}
		printf("\n");
	}

	/* Cerca lo 0 */
	//prima
	trovato = 0;

	//i = 0;
	//while (i < N && trovato == 0)
	//{
	//	//faccio cose
	//	i++;
	//}

	for (i = 0; i < N && trovato == 0; i++)
		for (j = 0; j < M && trovato == 0; j++)
			if (m[i][j] == 0) {
				trovato = 1;
				printf("primo 0 in %d  %d", i, j);
			}

	//ultima
	trovato = 0;
	for (i = N - 1; i >= 0 && trovato == 0; i--)
		for (j = M - 1; j >= 0 && trovato == 0; j--)
			if (m[i][j] == 0) {
				trovato = 1;
				printf("ultimo 0 in %d %d", i, j);
			}

	//mediana 
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			if (m[i][j] == 0) {
				cont++;	//cont = cont + 1;
			}

	if (cont % 2 == 0)
		cont = cont / 2;
	else
		cont = cont / 2 + 1;

	//cont = (cont % 2==0) ? cont / 2 : cont / 2 + 1;
	
	trovato = 0;
	for (i = 0; i < N && trovato==0; i++)
		for (j = 0; j < M && trovato == 0; j++)
			if (m[i][j] == 0) {
				cont2++;
				if (cont2 == cont) {
					printf("%d %d ", i, j);
					trovato = 1;
					//return 0;				
				}
			}
	//system("pause");
	//getchar();
	return 0;
}


int main2() {
	int m[N][N], i, j, lastI = -1, lastJ = -1, cont = 0;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			printf("\nInserisci un elemento della matrice [%d][%d]: ", i, j);
			scanf("%d",&m[i][j]);
		}
	}
	printf("\nLa matrice inserita e': \n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++)
			printf(" %d ", m[i][j]);
		printf("\n");
	}

	//primo 0
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			if (m[i][j] == 0) {
				cont++;
				lastI = i;
				lastJ = j;
				if (cont == 1) {
					printf("primo 0 in %d  %d", i, j);
				}
			}
	//ultimo 0
	if (lastI != -1) { //(cont>0)
		printf("ultimo 0 in %d %d", lastI, lastJ);
	}

	cont = (cont + 1) / 2;

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			if (m[i][j] == 0) {
				cont--;
				if (cont == 0) {
					printf("valore mediano %d %d ", i, j);
					return 0;
				}
			}
	return 0;
}