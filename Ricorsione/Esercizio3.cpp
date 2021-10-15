#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Si progetti la funzione ricorsiva che svolge il compito seguente.
Siano dati due vettori V1 e V2, di dimensione N1 e N2,
rispettivamente (con 1 <= N2 <= N1).

v2 = 11 2 3 4 |5
v1 = 3 5| 2 4 7 3 9 2 8 9

La funzione restituisce il valore 1 in uscita se tutti gli elementi del vettore V2
si trovano nel vettore V1 nell’ordine inverso rispetto
a quello in cui essi figurano in V2,
ma non necessariamente in posizioni immediatamente consecutive;

altrimenti (ovvero se questo non si verifica), la funzione restituisce valore 0.

*/
#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

#define N1 10
#define N2 5
int VETT1[N1], VETT2[N2], esito;


int contiene(int V1[], int V2[], int iniz, int fine) {
	if (fine < 0) 	// vettore V2 vuoto 
		return 1;   // termina con esito positivo	

	if (iniz > N1 - 1 )	// vettore V1 vuoto 
		return 0;	// termina con esito negativo 

	// passo induttivo e chiamata ricorsiva 
	if (V1[iniz] == V2[fine]) 	//caso 1 -  ho trovato un elemento avanzo sia v1 che v2
		return contiene(V1, V2, iniz + 1, fine - 1);

	return contiene(V1, V2, iniz + 1, fine); // caso 2	- non ho trovato un elemento vado avanti solo nel vettore v1
}


int contiene2(int V1[], int V2[], int n1, int fine) {
	if (fine < 0) 	// vettore V2 vuoto 
		return 1;   // termina con esito positivo	

	if (n1<0)	// vettore V1 vuoto 
		return 0;	// termina con esito negativo 

	// passo induttivo e chiamata ricorsiva 
	if (V1[0] == V2[fine]) 	//caso 1 -  ho trovato un elemento avanzo sia v1 che v2
		return contiene(&V1[1], V2, n1-1, fine - 1);

	return contiene(&V1[1], V2, n1-1, fine); // caso 2	- non ho trovato un elemento vado avanti solo nel vettore v1
}


int main()
{
	int esito = contiene(VETT1, VETT2, 0, N2 - 1);

	system("pause");

	return 0;
}

