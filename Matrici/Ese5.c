#include<stdio.h>

/* Esercizio (tde 13-7-2016)
Una matrice quadrata Mat di dimensioni NxN (con N costante predefinita)
è diagonalmente dominante se la somma dei valori assoluti degli elementi su ciascuna riga,'
escluso l'elemento sulla diagonale principale,
è minore del valore assoluto dell'elemento corrispondente sulla diagonale principale.
Scrivere un programma che chiede all’utente di inserire i valori di
una matrice e stampa «Dominante» se la matrice è diagonalmente dominante,
«Non dominante» altrimenti. 
Si ricorda che la funzione int abs(int n) restituisce
il valore assoluto dell’intero n ricevuto come parametro.
*/

#define N 10
int main() {
    int mat[N][N],i,j, diag, ele, dom = 1;

    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) {
            printf("inserire il valore alla riga %d ed alla colonna %d : ", i , j);
            scanf("%d",&mat[i][j]);
        }

    for (i = 0; i < N && dom; i++) {
        diag = 0; ele = 0;
        for (j = 0; j < N; j++)
            if (j == i) //sono sulla diagonale
                diag = abs(mat[i][j]);
            else //altri elementi
                ele += abs(mat[i][j]);
        if (diag <= ele)
            dom = 0;
    }
    if (dom)
        printf("Dominante\n");
    else
        printf("Non dominante\n");
}
