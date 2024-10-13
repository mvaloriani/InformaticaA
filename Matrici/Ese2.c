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
    } while (neg < 2 && i < 50);

    return 0;
}
