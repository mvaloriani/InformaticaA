#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Si consideri il seguente programma C, completando la 
definizione di MATR con la propria matricola.
#define MATR "......"   	 Ad esempio, "623372"  

Indicare le quattro righe di output stampate dal programma, 
simulandone l’esecuzione(si presti attenzione a “impilare” 
e “disimpilare” bene le chiamate ricorsive e a considerare 
tutte le chiamate alla funzione printf).

Si tenga anche presente che i caratteri '0', '1', …, '9' 
hanno codici ASCII consecutivi, crescenti in quest’ordine,
ed eventualmente che il carattere successivo a '9' è il carattere ':'.
Per ogni linea si dia una breve giustificazione, 
spiegando come opera la funzione ricorsiva corrispondente.

*/

#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema
#include <string.h>  // include libreria per gstione stringhe


#define MATR "623372"   	/* Ad esempio "623372" */

void f(char * p) {
	if (*p != '\0')
		f(p + 1);
	printf(".%s", p);
}


char * f3(char * p) {
	if (strlen(p) != 0)
		if (strlen(f3(p + 1)) == 2)
			printf("%s", p);
	return p;
}

int f2(char * p) {
	if (strcmp(p, "") == 0)
		return 0;
	else
		return f2(p + 1) + ((*p) - '0');
}

/* ATT: d è un doppio puntatore */
void f4(char ** d) {
	if (strlen(*d) > 0) {
		printf("%c", ((**d) + 1));
		++(*d);
		f4(d);
	}
}


int main() {
	char m[7] = MATR;
	char *x = m;
	f(m);

	printf("\n%d - %s\n", f2(m), m);

	printf(" - %s\n", f3(m));

	f4(&x);

	printf("\n");
	system("pause");
	return 0;
}

