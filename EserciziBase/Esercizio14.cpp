#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Dato un carattere in ingresso, trasformarlo 
in un altro carattere, che si trova OFFSET 
posizioni più in là nell'alfabeto
L'alfabeto considerato è:
ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
L'alfabeto è ciclico: dopo la ‘z' c'è la ‘A'
Per esempio, con OFFSET = 4
il carattere 'a' diventa 'e'
la lettera 'X' diventa 'b'
la lettera ‘x' diventa ‘B'

La complessità del programma sta tutta nel fatto 
che nella codifica ASCII le sequenze 'A'..'Z' e 'a'..'z' 
(viene prima la sequenza di caratteri maiuscoli) non 
sono consecutive, ma c'è di mezzo un altro insieme di caratteri,
per cui occorre spezzare il programma in 2 if.

*/

#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema
#define OFFSET 4


char main() {
	char curr, newvalue;
	printf("Inserisci il carattere alfabetico da convertire: ");
	scanf("%c", &curr);

	if (curr >= 'A' && curr <= 'Z') {
		newvalue = curr + OFFSET;
		if (newvalue > 'Z') {
			newvalue = newvalue + ('a'-'Z') - 1;
		}
		printf("Il nuovo carattere dopo la conversione e': %c\n", newvalue);
	}
	else if (curr >= 'a' && curr <= 'z') {
		newvalue = curr + OFFSET;
		if (newvalue > 'z') {
			newvalue = 'A' + (newvalue - 'z'-1);
		}
		printf("Il nuovo carattere dopo la conversione e': %c\n", newvalue);
	}
	else {
		printf("Non e' stato immesso un carattere valido\n"); 
	}


	printf("\n");
	system("pause");

	return 'a';
}
