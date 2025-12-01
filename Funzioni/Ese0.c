/*Scrivere in C una funzione f che ha in ingresso un vettore A
di interi già caricato e restituisce, attraverso un opportuno parametro,
un vettore di tipo che contiene gli stessi elementi del vettore di 
ingresso ma in ordine inverso, inoltre la funzione restituisce il
prodotto di tutti gli elementi di A.
*/


#include <stdlib.h>
#include <stdio.h>

#define N 10
int f(int A[], int B[]);

int main() { //non richiesto dal testo
    int v[N] = { 2,-4,8,9,12,1,6,-9,5,3 }, w[N];
    int j;
    for (j = 0; j < 10; j++)
        printf("%d\n", v[j]);
    
    int p = f(v, w);
    f(v, w, &p);

    printf("prodotto: %d\n", p);
    
    for (j = 0; j < 10; j++)
        printf("%d\n", w[j]);
    return 0;
}


int f(int A[], int B[]) {
    int i, prod = 1;
    for (i = 0; i < N; i++) {
        B[N - i - 1] = A[i];
        prod = prod * A[i];
    }
    return prod;
}

void f(int A[], int B[], int* prodotto) {
    int i, *prod = 1;
    for (i = 0; i < N; i++) {
        B[N - i - 1] = A[i];
        *prod = *prod * A[i];
    }
}

