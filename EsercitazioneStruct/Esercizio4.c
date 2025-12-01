#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*Si scriva un frammento di codice, che includa eventualmente anche le
dichiarazioni di ulteriori variabili e tipi, che copi nella parte
iniziale del vettore personeScelte  (senza lasciare buchi):
le persone che parlano inglese con un livello superiore a 3
oppure hanno non meno di una laurea e un numero di anni di esperienza
non inferiore a tre.
*/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef char lingua[20];
typedef char stringa[20];

typedef struct {
	//char l[20]
	lingua l;
	int livello; /* numero da 1 a 5 con 1=basso 5=alto */
} linguaParlata;

typedef struct {
	stringa nome, cognome, diploma, laurea;
	linguaParlata lingue[5];
	int nLauree;
	int anniEsperienza;
} persona;

/* definizioni delle variabili */
persona persone[40];
persona personeScelte[40];

int main() {

	int iPersone, iPersoneScel, iLingue;
	iPersoneScel = 0;

	int selezionato = 0;

	//scorro la lista delle persone
	for (iPersone = 0; iPersone < 40; iPersone++) {
		//selezionato = 0;
		// persone con + di 1 laurea e + di 3 anni di esperienza
		if (persone[iPersone].nLauree >= 1 &&
			persone[iPersone].anniEsperienza >= 3) {
			selezionato = 1;
		}

		else {
			// cerco se parla inglese con livello maggiore di 3
			for (iLingue = 0; iLingue < 5; iLingue++) {
				if (strcmp(persone[iPersone].lingue[iLingue].l, "inglese") == 0
					&& persone[iPersone].lingue[iLingue].livello > 3) {
					selezionato = 1
				}
			}
		}
		if (selezionato == 1) {

			personeScelte[iPersoneScelte] = persone[iPersone];
			iPersoneScelte++;
			selezionato = 0;
		}

	}


	for (int i = 0; i < iPersoneScel; i++)
	{
		printf("%s", personeScelte[i], nome);
	}

	return 0;
}

int main2() {

	int iPersone, iPersoneScel, iLingue;
	iPersoneScel = 0;

	//scorro la lista delle persone
	for (iPersone = 0; iPersone < 40; iPersone++) {
		// persone con + di 1 laurea e + di 3 anni di esperienza
		if (persone[iPersone].nLauree >= 1 &&
			persone[iPersone].anniEsperienza >= 3) {
			personeScelte[iPersoneScelte] = persone[iPersone];
			iPersoneScelte++;
			continue;
		}
		// cerco se parla inglese con livello maggiore di 3
		for (iLingue = 0; iLingue < 5; iLingue++) {
			if (strcmp(persone[iPersone].lingue[iLingue].l, "inglese") == 0
				&& persone[iPersone].lingue[iLingue].livello > 3) {
				personeScelte[iPersoneScelte] = persone[iPersone];
				iPersoneScelte++;
			}
		}
	}

	for (int i = 0; i < iPersoneScel; i++)
	{
		printf("%s", personeScelte[i], nome);
	}

	return 0;
}