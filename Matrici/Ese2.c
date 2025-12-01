#include<stdio.h>
#include<stdlib.h>

/*
Scrivere un programma C che legge una sequenza di numeri interi
e li mette nella prima riga della matrice M. 
La lettura della sequenza termina quando alla prima riga
della matrice M sono stati assegnati 50 interi oppure
quando viene letto il secondo numero intero negativo.
*/

#define N 50
int main() {
    int mat[N][N], i = 0, neg = 0;

    do {
        scanf("%d", &mat[0][i]);
        if (mat[0][i] < 0)
            neg++;
        i++;
    } while (neg < 2 && i < N);
        
    //for (i=0;i<N && neg < 2; i++)
    //{
    //    scanf("%d", &mat[0][i]);
    //    if (mat[0][i] < 0)
    //        neg++;
    //}


    for (int j = 0; j < i;  j++)
    {
        printf("%d", mat[0][j]);
    }


    return 0;
}
