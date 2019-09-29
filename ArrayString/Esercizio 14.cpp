#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*Esercizio (tdeB 21-7-2006)
Definiamo il grado minimo g e il grado massimo G di una parola P 
rispettivamente come il minimo e il massimo numero 
di occorrenze delle lettere di P in P.  
Ad esempio:
ISTANBUL   g=1, G=1  ( tutte le lettere della parola compaiono in essa una e una sola volta )
BOSFORO	   g=1, G=3  ( B, S, F, R compaiono una sola volta, O compare tre volte )
GALATASARAY    g=1, G=5  ( G, L, T, S, R, Y compaiono una sola volta, A compare cinque volte )
MARMARA    g=2, G=3  ( M e R compaiono due volte, A compare tre volte )
G e g valgono convenzionalmente 0 per la parola vuota (cioè per una parola priva di caratteri).
Si scriva un programma C che legge una stringa 
di lunghezza generica che rappresenta P, calcola G e g, e li stampa

*/

#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema
#include <string.h>  // inclusione libreria standard per gestione stringhe

int main() {
	char p[100]; int g, G, i, j, count, lun;
	
	printf("inserire una stringa: ");
	scanf("%s", p);
	lun = strlen(p);
	
	g = lun;
	G = 0;
	for (i = 0; i<lun; i++) {
		count = 0;
		for (j = 0; j<lun; j++) {
			if (p[i] == p[j]) {
				count++;
			}
		}
		if (count < g)
			g = count;
		if (count > G)
			G = count;
	}
	printf("g = %d, G = %d", g, G);


	printf("\n");
	system("pause");
	return 0;
}

