#include<stdio.h>

/* Esercizio (tdeB 20-7-2010)
Considerata una matrice A di N x M interi, 
definiamo claque una sottomatrice 2 x 2 in cui la somma algebrica dei valori
di una diagonale sia pari a quella dell’altra diagonale. In figura sono evidenziate le claque.

Si scriva un programma che acquisisce una matrice N x M e
stampa il numero di claque della matrice.
*/

#define N 10
#define M 10

int main() {
    int m[N][M], i, j, cont = 0;

    printf("Inserisci %d elementi\n", N * M);
    for (i = 0; i < N; i++)
        for (j = 0; j < M; j++)
            scanf("%d",&m[i][j]);

    for (i = 0; i < N - 1; i++)
        for (j = 0; j < M - 1; j++)
            if (m[i][j] + m[i + 1][j + 1] - m[i + 1][j] - m[i][j + 1]  == 0)
                cont++;

    printf("Le claque sono %d\n", cont);

    return 0;
}

