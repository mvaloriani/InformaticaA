#include<stdio.h>

/*
Si realizzi un programma in linguaggio C che, 
data una matrice NxM di interi, 
trovi l’elemento per cui la media degli elementi ad esso adiacenti sia massima.
Si stampino le coordinate di tale elemento ed il suo valore.
Si considerino come adiacenti a ciascun elemento i quattro elementi 
nelle quattro direzioni cardinali.
Si tratti inoltre l’ultima colonna come adiacente alla prima,
e l’ultima riga come adiacente alla prima. 
Si supponga che N ed M possano variare tra 1 e 100. I
valori di N ed M, così come i valori degli elementi della matrice, vengono acquisiti da tastiera.
*/

int main() {
	int mat[100][100], N, M, i, k, up, left, down, right, i_max, k_max, max;
	printf("Inserisci dimensioni della matrice");
	do {
		scanf("%d", &N);
	} while (N > 100 || N <= 0);
	do {
		scanf("%d", &M);
	} while (M > 100 || M <= 0);

	for (i = 0; i < N; i++) {
		for (k = 0; k < M; k++) {
			scanf("%d", &mat[i][k]);
		}
	}

	max = mat[0][1] + mat[1][0] + mat[2][1] + mat[1][2];
	i_max = 1;
	k_max = 1;
	
	for (i = 0; i < N; i++) {
		for (k = 0; k < M; k++) {
			//la riga sopra da confrontare
			if (i - 1 >= 0) up = i - 1;
			else up = N - 1;
			//la colonna a sinistra da confrontare
			if (k - 1 >= 0) left = k - 1;
			else left = M - 1;
			//il %N serve perché se col +1 supero N, torno alla prima riga
			down = (i + 1) % N;
			right = (k + 1) % N;
			
			if (mat[up][k] + mat[i][left] + mat[down][k] + mat[i][right] > max) {
				max = mat[up][k] + mat[i][left] + mat[down][k] + mat[i][right];
				i_max = i;
				k_max = k;
			}
		}
	}
	printf("%d %d", i_max, k_max);
}

