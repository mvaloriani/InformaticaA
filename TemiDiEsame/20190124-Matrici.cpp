/*Esercizio  4  (6 punti)
Scrivere una funzione verifica che prende in ingresso una matrice di
caratteri M di dimensioni NxN(supponendo N predefinita con #define),
una stringa S, e due indici i e j.

La funzione verifica se in M esiste un percorso connesso
(una sequenza di celle consecutive in direzione verticale,
orizzontale o diagonale) che inizia nella posizione(i, j)
che corrisponde a S.

Se il percorso esiste la funzione restituisce 1, altrimenti 0.
Per semplicità si supponga di poter passare più volte sulla
stessa cella della matrice M mentre si ricerca la parola S.

Con M =

	a c k
	s m o
	d o i

S = “amo”, i = 0, j = 0; La funzione restituisce 1
Invece con la stessa M, ma S = “doc”, i = 2, j = 0;
La funzione restituisce 0.
*/

#define N 4

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>


int F(char M[N][N], char* S, int i, int j) {

	int len = strlen(S);
	int count = 0;

	if (len == 0) return 0;

	if (i < 0 || j < 0 || i >= N || j >= N) return 0;

	if (M[i][j] != S[0]) return 0;

	if (len == 1) return 1;

	for (int x = -1; x <= 1; x++) {
		for (int y = -1; y <= 1; y++) {
			if (x == 0 && y == 0) continue

			count = count + F(M, &S[1], i + x, j + y);
		}
	}
	return count > 0 ? 1 : 0;

}