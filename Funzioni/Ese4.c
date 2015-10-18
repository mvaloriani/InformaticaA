/*
Definire un nuovo tipo di dato di nome NUMERI, struttura con due campi di nome b2 e cpl2 entrambi di tipo vettore di 10 componenti di tipo int. 
Scrivere una funzione di nome F con un parametro formale di nome X di tipo NUMERI passato per indirizzo. La funzione deve assegnare al campo cpl2 di X il risultato del complemento a 2 del numero nel campo b2 di X.
Nota: se il complemento a 2 di b2 non esiste, allora la funzione può mettere in cpl2 quello che vuole.

*/
#include <stdlib.h>
#include <stdio.h>

typedef struct{ int b2[10], cpl2[10]; } NUMERI;

f(NUMERI *X){
	int i = 10;
	do {
		i--;
		X->cpl2[i] = X->b2[i];
	} while (X->b2[i] != 1 && i>0);
	i--;
	while (i >= 0) {
		X->cpl2[i] = 1 - X->b2[i];
		i--;
	}
}

int main() {
	NUMERI  v = { { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 }, 0 };
	f(&v);
	//printf("%d\n", );
	system("pause");     return 0;
}


