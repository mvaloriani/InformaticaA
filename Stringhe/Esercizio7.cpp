#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Esercizio (tdeB 10-9-2012)
Due parole p, q si definiscono allacciabili se
un suffisso proprio s di p è anche prefisso proprio
di q, cioè hanno la forma p=w1s  q=sw2 (dove s è proprio se è lungo almeno 2 lettere).
Esempi di parole allacciabili:
(oca, carina)    ocarina          
(coraggio, raggio)      coraggio 
(bugiardi, giardino)    bugiardino (dei farmaci)
(spora, radici)      sporadici          
(imposta, stazione)      impostazione  

Esempi di coppie non allacciabili:
(violoncello, cellulare), (corpo, orazione)

Si codifichi in C un frammento di codice che
stampa la lunghezza del massimo suf-/pre-fisso proprio
in comune tra le due stringhe p e q (cioè la lunghezza
di s, se p=w1s  q=sw2) e che inserisce nella stringa t la
parola ottenuta dall’allacciatura che fattorizza la massima
sovrapposizione, oppure la stringa vuota se le parole non sono allacciabili

*/

#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema
#include <string.h>  // inclusione libreria standard per gestione stringhe

#define LUNG 100

int main() {
	char str1[LUNG], str2[LUNG], t[2 * LUNG];
	int maxsuf = 0;

	t[0] = '\0';

	printf("inserire una stringa 1: ");
	scanf("%s", str1);

	printf("inserire una stringa 2: ");
	scanf("%s", str2);

	// csasa
	// sale

	for (int i = 0; i < strlen(str1); i++)
	{
		if (str1[i] == str2[maxsuf]) {
			maxsuf++;
		}
		else {
			if (maxsuf > 0)
				i= i-maxsuf;
			maxsuf = 0;
		}
	}

	if (maxsuf > 1) {
		//Soluzione 1
		strcpy(t, str1);
		strcat(t, &str2[maxsuf]);

	
		//Soluaizone 2
		for (int i = 0; i < strlen(str1); i++)
		{
			t[i] = str1[i];
		}
		for (int j = 0; j < strlen(str2); j++)
		{
			if (j >= maxsuf)
				t[strlen(str1) - maxsuf + j] = str2[j];
		}
		t[strlen(str1) + strlen(str2) - maxsuf] = '\0';
	}



	printf("Lunghezza massimo prefisso: %d", maxsuf);

	printf("\n stringa allacciata: %s", t);

	printf("\n");
	system("pause");
	return 0;
}

