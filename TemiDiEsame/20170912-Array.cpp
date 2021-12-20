/*
Esercizio  4  ( 4 punti )
Si scriva un sottoprogramma che ricevuto in ingresso un array A di float di dimensione N
(costante predefinita con #define N …) ed un valore intero X, stampa a video i valori che
costituiscono gli X massimi valori contenuti nell’array A in ordine decrescente.

Ad esempio, se il sottoprogramma riceve in ingresso l’array seguente ed il valore X=3

10 2 3 23 101

verranno stampati i valori

101 23 10

*/


#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define N 10

void stampaMax(float A[N], int x) {

    bubbleSort(A, N);
    for (int i = 0; i < x; i++)
    {
        printf(" % f \n", A[N - i]);
    }
}

void bubbleSort(float arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)

        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}

void swap(float* a, float* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}