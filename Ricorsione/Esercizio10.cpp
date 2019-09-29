#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Si consideri il seguente programma C, completando la definizione di MATR con la propria matricola.
#define MATR "......"    Ad esempio "623372"

Si spieghi brevemente il comportamento del programma;
per comprenderlo, si suggerisce di simularne l’esecuzione
(prestando attenzione a “impilare” ed eventualmente “disimpilare”
bene le chiamate ricorsive e a prestare attenzione a quali istruzioni
sono eseguite e quali no).

Indicare anche l’output stampato a video dal programma
(attenzione alla posizione delle chiamate a printf).


*/

#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema
#include <string.h>  // include libreria per gstione stringhe


#define MATR "623372"   	/* Ad esempio "623372" */
#define CIFRE "0987654321"

void f(char *);
void g(char *);

void g(char * p) {
	if (strlen(p) == 0)
		return;
	else {
		f(p - 1);         /* -1 !! */
		printf("%c", *p);
		return;
	}
}

void f(char * p) {
	if (p == NULL)
		return;
	else {
		printf("%c", *p);
		g(p + 1);         /* +1 !! */
		return;
	}
}

int main() {
	char m[7] = MATR;
	f(m + 4);
	printf("SE ARRIVO QUI HO FINITO\n");

	system("pause");
	return 0;
}
