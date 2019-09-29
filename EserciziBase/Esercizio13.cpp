#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Si scriva un programma in linguaggio C che
riceve dallo standard input due caratteri alfabetici,
li converte in maiuscolo e stampa a video
ordinatamente tutti i caratteri dell'alfabeto
fra essi  compresi, estremi inclusi.
Esempio: dati 'g' e 'M‘ stampa a video la sequenza: GHIJKLM.

*/

#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

int main() {
	char x, y, t;
	do {
		printf("\n Inserisci il carattere x: ");
		scanf("%c", &x);
	} while (!(((x >= 'a') && (x <= 'z')) || ((x >= 'A') && (x <= 'Z'))));

	do {
		printf("\n Inserisci il carattere y: "); scanf("%c", &y);
	} while (!(((y >= 'a') && (y <= 'z')) || ((y >= 'A') && (y <= 'Z'))));

	/* converte i caratteri nel corrispondente maiuscolo */
	if ((x >= 'a') && (x <= 'z'))
		x = x - 'a' + 'A';

	if ((y >= 'a') && (y <= 'z'))
		y = y - 'a' + 'A';

	if (x > y) {  /* ordina x,y  - swap di variabili */ 
		t = x;  
		x = y;  
		y = t; } 

	//if (x > y) {  /* ordina x,y - swap di variabili intere senza variabile aggiuntiva*/
	//	x = x+y;
	//	y = x-y;
	//	x = x-y;
	//}

	//if (x > y) {  /* ordina x,y - swap di variabili senza variabile aggiuntiva*/
	//	x = x ^ y;
	//	y = x ^ y;
	//	x = x ^ y;
	//}

	printf("\n La sequenza di caratteri richiesta e': ");
	while (x <= y) {
		printf("%c", x);
		x = x + 1;
	}


	printf("\n");
	system("pause");

	return 0;
}
