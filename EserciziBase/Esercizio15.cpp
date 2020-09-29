#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Scrivere un programma in linguaggio C per la rappresentazione
del triangolo di Floyd. Il triangolo di Floyd è un triangolo
rettangolo che contiene numeri naturali, definito riempiendo
le righe del triangolo con numeri consecutivi e partendo da
1 nell’angolo in alto a sinistra.
Si consideri ad esempio il caso N=5. Il triangolo di Floyd
è il seguente:
	1
	2 3
	4 5 6
	7 8 9 10
	11 12 13 14 15
Il programma riceve da tastiera un numero intero N.
Il programma visualizza le prime N righe del triangolo di Floyd.
Suggerimento. Si osserva che il numero di valori in ogni
riga corrisponde all’indice della riga: 1 valore sulla
prima riga, 2 sulla seconda, 3 sulla terza.
Estensione: si risolva il problema usando un ciclo solo

*/

#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

int main() {

	int N;
	printf("Inserire numero di righe: ");
	scanf("%d", &N);

	int i = 1, count = 0, riga= 1;

	//scrivo il triangolo fino alla riga N
	while (riga <= N) {

		printf("%d ", i);
		i++;
		count++;

		if (count == riga) {
			count = 0;
			riga++;
			printf("\n");
		}
	}


	//scrivo il triangolo fino al numero N
	/*while (i <= N) {
		//ciclo da 1 a N

		printf("%d ", i);
		i++;
		count++;

		if (count == riga ) {
			count = 0;
			riga++;
			printf("\n");
		}
	}*/

	printf("\n");
	system("pause");

	return 0;
}
