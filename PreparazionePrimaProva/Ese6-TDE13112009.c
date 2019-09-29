/*
Definito il tipo punto
typedef struct {int x; 
int y;
int NMonete; 
} punto;
scrivere una funzione che riceve in input una matrice M di punti 
di dimensione N*N e due coordinate x, y.
La funzione deve navigare la matrice, partendo dal punto indicato dalle
coordinate x e y e spostarsi ogni volta nelle coordinate indicate dal punto raggiunto.
Nello spostarsi la funzione deve sommare tutti i valori di NMonete incontrati.
La funzione procede allo stesso modo finché o non torna su un punto già toccato
o trova coordinate non valide. A quel punto restituisce la somma delle monete raccolte.
*/

#include <stdio.h>
const int N=100;

typedef struct {
	int x; 
	int y;
	int NMonete; 
} punto;

int caccia(punto M[N][N], int x, int y) {
	int i,j,totale=0, M2[N][N], aux;

	//azzero la matrice M2
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			M2[i][j]=0;

	//Scorro la matrice finche ho degli 0 o noon esco 
	while(x>=0 && x<N && y>=0 && y<N && M2[x][y]==0){
		//assegno 1
		M2[x][y]=1;
		//sommo le monete
		totale=totale+M[x][y].NMonete;
		// aggiorno le coordinate
		aux=M[x][y].x;
		y=M[x][y].y;
		x=aux;
	}

	return totale;
}
