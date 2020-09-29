#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Si scriva un programma che legge una 
sequenza di caratteri (la sequenza
termina quando viene inserito il carattere "#"),
conta il numero complessivo di lettere minuscole
comprese nella sequenza e stampa questo valore.

Per esempio, nel caso la sequenza in ingresso fosse
defghi123jklmaAAa002#
il programma dovrebbe stampare il valore 12.

*/

#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

int main() {

	char car;
	int contatore = 0;
	printf("Inserire una serie di caratteri(# per finire)\n");
	do {
		scanf("%c", &car);
		if (car >= 'a' && car <= 'z')
			contatore++;
	} while (car != '#');
	printf("Il numero delle lettere minuscole e' %d", contatore);
	 

	printf("\n");
	system("pause");
	return 0;
}
