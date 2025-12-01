#include<stdio.h>

/* Esercizio (tdeB 20-7-2010)
Si scriva un programma che chiede all’utente di riempire una matrice NxN 
(con N costante globale predefinita), un intero len 
(che deve essere un intero positivo maggiore di 1) e
stampa OK se in m è presente almeno una sequenza orizzontale,
verticale o diagonale, di lunghezza len, 
di elementi che crescono o diminuiscono linearmente 
(cioè in cui la differenza tra due elementi successivi è costante).
Esempi di sequenze lineari:
	1 2 3 4 (lunghezza 4, differenza costante 1)
	4 3 2 1 (lunghezza 4, differenza constante -1)
	5 5 5 5 5 5 5 (lunghezza 7, differenza costante 0)
Sono ammesse anche sequenze di lunghezza 1 (che è considerata sempre lineare)

Esempio (con matrice 5 per 5, per semplicità):
	3	6	7	5	3
	5	6	2	9	1
	2	7	0	9	3
	6	0	6	2	6
	1	8	7	9	2
se len è 4, la funzione deve restituire 0,
perché non c'è nessuna sequenza lineare di lunghezza 4,
se len è 3, la funzione restituisce 1,
perché è presente la sequenza orizzontale 7 5 3, con differenza costante -2
*/

#define N 5

int main() {
	int m[N][N], len, i, j, new_diff, diff, durata;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			printf("Inserire valore in A[%d][%d]: ", i, j);
			scanf("%d", &m[i][j]);
		}

	do {
		printf("Inserire valore di len positivo > 1");
		scanf("%d", &len);
	} while (len<1 || len>N);
	printf("/n");

	//Orizzontale
	for (i = 0; i < N; i++) {
		diff = m[i][1] - m[i][0];
		durata = 1;
		for (j = 2; j < N; j++) {
			new_diff = m[i][j] - m[i][j - 1];
			if (new_diff == diff)
				durata++;
			else {
				diff = new_diff;
				durata = 1;
			}
			if (durata == len - 1) {
				printf("Trovata seq orizzontale di lung. %d da m[%d][%d] a m[%d][%d]\n", len, i, j - len + 1, i, j);
				return 1;
			}
		}
	}

	//Verticale
	for (j = 0; j < N; j++) {
		diff = m[1][j] - m[0][j];
		durata = 1;
		for (i = 2; i < N; i++) {
			new_diff = m[i][j] - m[i - 1][j];
			if (new_diff == diff)
				durata++;
			else {
				diff = new_diff;
				durata = 1;
			}
			if (durata == len - 1) {
				printf("Trovata seq verticale di lung. %d da m[%d][%d] a m[%d][%d]\n", len, i - len + 1, j, i, j);
				return 1;
			}
		}
	}

	//Diagonale da sx a dx parte sopra (inclusa diag principale)
   //iteratore del numero di diagonale
	for (i = 0; i < N; i++) {
		diff = m[1][i + 1] - m[0][i];
		durata = 1;
		//iteratore lungo la singola diagonale
		for (j = 2; j < N - i; j++) {
			new_diff = m[j][j + i] - m[j - 1][j - 1 + i];
			if (new_diff == diff)
				durata++;
			else {
				diff = new_diff;
				durata = 1;
			}
			if (durata == len - 1) {
				printf("Trovata seq diagonale (superiore) di lung. %d da m[%d][%d] a m[%d][%d]\n", len, j - len + 1, j + i - len + 1, j, j + i);
				return 1;
			}
		}
	}

	//Diagonale da sx a dx parte sotto (esclusa diag principale)
   //iteratore del numero di diagonale
	for (i = 1; i < N; i++) {
		diff = m[i + 1][1] - m[i][0];
		durata = 1;
		//iteratore lungo la singola diagonale
		for (j = 2; j < N - i; j++) {
			new_diff = m[j + i][j] - m[j - 1 + i][j - 1];
			if (new_diff == diff)
				durata++;
			else {
				diff = new_diff;
				durata = 1;
			}
			if (durata == len - 1) {
				printf("Trovata seq diagonale (superiore) di lunghezza %d da m[%d][%d] a m[%d][%d]\n", len, j + i - len + 1, j - len + 1, j + i, j);
				return 1;
			}
		}
	}





