/*
Si completi il programma sottostante, dove puzzle è una matrice 
di caratteri di R righe e C colonne che rappresenta un cruciverba.
Le caselle nere sono rappresentate dal carattere '*'
Si vogliono numerare le parole di almeno due lettere secondo la consueta
numerazione dei cruciverba, partendo dalle celle in alto a sinistra e
procedendo in ordine lessicografico Ad esempio, la matrice dichiarata nel 
programma corrisponde allo schema mostrato in figura (il numero di ciascuna parola è indicato nella cella contenente la prima lettera della parola)

Il programma deve determinare la numerazione delle parole e stampare,
per ogni numero, le coordinate (riga e colonna) della casella a cui si riferisce 
e se si tratta di una parola orizzontale, verticale o sia orizzontale che verticale.

Con la matrice dichiarata nel programma, l'output è come segue.
Parola 1: riga 0, colonna 0 verticale orizzontale
Parola 2: riga 0, colonna 1 verticale
Parola 3: riga 0, colonna 4 verticale
Parola 4: riga 1, colonna 0 orizzontale
Parola 5: riga 1, colonna 3 verticale orizzontale
Parola 6: riga 2, colonna 0 orizzontale
Parola 7: riga 3, colonna 3 orizzontale

Per l'implementazione si realizzi e si faccia uso di una funzione con il seguente prototipo
int iniziaParola(int m[][C], int r, int c, Direzione d);
che controlli se alla riga r e colonna c inizi una parola di almeno due
lettere nella matrice m lungo la direzione d (orizzontale se d è 0, verticale altrimenti). 
Si noti che una parola inizia in una certa casella se è preceduta, lungo la direzione considerata,
o da una casella nera o dal bordo del puzzle.


*/

#include <stdio.h>
#define R 4
#define C 5
#define Orizzontale 0
#define Verticale 1

#include <stdio.h>

int main() {
	char m[R][C] = {{'A','B','I','*','I'},{'T','O','*','E','R'},{'O','B','A','M','A'},{'S','*','*','I','Q'}};
	int n=0,parolaOriz, parolaVert;
	for (int r=0;r<R;r++) {
		for (int c=0;c<C;c++) {
			//soluzione------------------------------------//
			parolaOriz=iniziaParola(m, r, c, Orizzontale);	//
			parolaVert=iniziaParola(m, r, c, Verticale);	//
			//---------------------------------------------//
			if (parolaVert || parolaOriz) {
				printf("Parola %d: riga %d, colonna %d", ++n, r, c);
				if(parolaVert)
					printf(" verticale");
				if(parolaOriz)
					printf(" orizzontale");
			}
		}
	}
}

int iniziaParola(char m[R][C], int r, int c, int d) {
	//casella nera;
	if (m[r][c] == '*') return 0;
	switch(d) {
	case Orizzontale:
		// sono sul bordo o prima c'è una casella nera
		if (c-1<0 || m[r][c-1]=='*')
			return c+1<C && m[r][c+1]!='*';
		return 0;
	case Verticale:
		if (r-1<0 || m[r-1][c]=='*') {
			return r+1<R && m[r+1][c]!='*';
		}
		return 0;
	default: 
		return 0;
	}
}

