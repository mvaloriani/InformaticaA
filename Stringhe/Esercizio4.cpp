#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Si codifichi un programma C che legge due stringhe
che rappresentano due parole e stampa un valore
intero, da interpretarsi come valore di verit�,
che indica se le parole sono anagrammi, cio� se
� possibile ottenere l�una dall�altra tramite
permutazione delle loro lettere.
Ad esempio le parole POLENTA e PENTOLA sono anagrammi.
Si presti attenzione al fatto che parole come TAPPO
e PATTO non sono anagrammi, anche se ogni
lettera dell�una � contenuta nell�altra.

*/

#include <stdio.h>   
#include <stdlib.h>
#include <string.h>

#define lung 10 
int main() {
	char a[100], b[100]; int len, contA, contB, i, k, si = 1;
	printf("Inserire parola 1\n"); 
	scanf("%s", a); 
	printf("Inserire parola 2\n");
	scanf("%s", b);

	len = strlen(a);

	if (len != strlen(b))
		si = 0; // non possono essere anagrammi se la lunghezza � diversa

	for (i = 0; i < len && si == 1; i++) {  //per ogni a[i] in a (escluso il \0)
		contA = 0; contB = 0;
		for (k = 0; k < len; k++) {  //scandisco le stringhe
			if (a[k] == a[i])
				++contA; //conto le occorrenze di a[i] in a
			if (b[k] == a[i])
				++contB; //e le occorrenze di a[i] in b
		}
		if (contA != contB)
			si = 0;
	}
	printf("%d\n", si);  // se corrispondono tutti -> 1



	system("pause");
	return 0;
}


