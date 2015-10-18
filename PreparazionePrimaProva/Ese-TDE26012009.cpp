/*
Si progetti e codifichi una funzione C che riceve in ingresso un array a di interi non negativi.
La funzione calcola il numero degli elementi dell’array che godono della seguente proprietà: 
il valore dell’elemento è pari al numero di elementi con valore inferiore considerando 
solo quelli in posizione precedente.
Ad esempio, si consideri il seguente vettore:
1 2 1 3 6 4 1 4 14
In questo caso solo i due numeri in grassetto (il 3 e il 4) 
soddisfano la proprietà descritta. Quindi la funzione restituisce 2.

*/

#include <stdio.h>
#define NumElementi(array) (sizeof(array)/sizeof(array[0]))

int contaPrec(int a[],int p) {
	int i=0,cont=0;

	for(i=0;i<p;i++) {
		if(a[i]<a[p])
			cont++;
	}
	return cont;
}

int f(int a[]) {
	int i,cont=0;
	int N = NumElementi(a);
	//cicli sull'array
	for(i=0;i<N;i++)
		//per ogni elemento valuto conto il numero di elemnti minori e 
		// verifico se è uguale al numero corrente
		if(contaPrec(a,i)==a[i])
			cont++;
	return cont;
}
