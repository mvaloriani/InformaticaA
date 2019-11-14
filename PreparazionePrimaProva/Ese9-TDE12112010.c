/*
Si scriva una funzione che riceve in input due array di dimensione N (con N costante predefinita).
void f(int a[], int b[])

Si definisce equibilatero un elemento di un vettore preceduto da tanti numeri pari più grandi 
quanti sono gli elementi dispari più piccoli che lo seguono. La funzione f deve copiare tutti 
gli elementi equibilateri di a in b in posizioni contigue partendo dalla prima posizione di b 
senza lasciare buchi. Le posizioni finali di b che restano libere devono essere riempite di zeri.
*/

#include <stdio.h>
#define N 100

void f(int a[], int b[]){
	int i,j=0;
	//ciclo sul vettore
	for(i=0;i<N;i++){
		// valuto la condizione
		if(f1(a,i)==f2(a,i)){
			//copio il valore e avanzo l'indice
			b[j] = a[i]; // *(a+i);
			j++;
		}
	}
	//completo con gli 0
	for(;j<N;j++)		
		b[j]=0;
}
int f1(int a[],int pos){
	int i,cont=0;
	//ciclo sul vettore fino alla posizione corrente
	for(i=0;i<pos;i++)
		//conto il numero elementi pari più grandi dell'elemento corrente
			if(a[i]%2==0 && a[i]> a[pos])
				cont++;
	return cont;
}

int f2(int a[],int pos){
	int i,cont=0;
	//ciclo dalla posizione corrente fino alla fine del vettore
	for(i=N-1;i>pos;i--)
		//conto il numero elementi dispari più piccoli dell'elemento corrente
			if(a[i]%2==1 && a[i]<a[pos])
				cont++;
	return cont;
}
