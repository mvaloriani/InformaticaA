/*
Scrivere un programma C che faccia quanto segue:
Legge una sequenza di numeri interi e quei numeri compresi tra 0 e 1023
vengono memorizzati in un vettore di nome V. La lettura termina quando nel
vettore sono stati inseriti 10 numeri

Per ogni numero in V il programma esegue la conversione in binario,
memorizza i resti ottenuti in un vettore R opportunamente dimensionato e stampa il contenuto di R

*/

#include<stdio.h>

#define N 10
#define MAXVAL 1023

int main() {
	int i=0,j,V[N],R[N];
	do {  scanf("%d",&V[i]);
	if (V[i]>=0 && V[i]<=MAXVAL)
		i++;
	} while(i<N); 
	for(i=0;i<N;i++){
		for(j=N-1;j>=0;j--){
			R[j]=V[i]%2;
			V[i]=V[i]/2;
		}
		for(j=0;j<N;j++)
			printf("%d ",R[j]);
		printf("\n");
	}  
	return 0;
}
