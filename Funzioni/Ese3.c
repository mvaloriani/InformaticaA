/*
Definire un nuovo tipo di dato di nome REC, struttura con due campi:
il primo campo, di nome b2, deve essse di tipo vettore di 10 componenti di tipo int;
il secondo campo, di nome b10, deve essere di tipo int.
Scrivere una funzione di nome F con un parametro formale di nome X di tipo REC
passato per indirizzo. La funzione deve assegnare al campo b10 di X il risultato
della conversione da base 2 a base 10 del numero dato nel campo b2 di X.
*/
#include <stdlib.h>
#include <stdio.h>


typedef struct{ int b2[10], b10; } REC;

void f(REC *X) {
	int i, peso = 1;

	X->b10 = 0;

	for (i = 9; i >= 0; i--){
		X->b10 = X->b10 + X->b2[i] * peso;
		peso = peso * 2;
	}
}

int main() { 
	REC  v = { {0,0,0,0,0,0,0,0,1,1}, 0 };
	f(&v);
	printf("%d\n", v.b10);
	system("pause");     return 0;
}


