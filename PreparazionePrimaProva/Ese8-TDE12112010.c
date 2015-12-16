/*
Si considerino le seguenti definizioni di tipo:
#define N 20	
typedef int matrice[N][N];
typedef matrice matmat[N][N];

Implementare una funzione C che riceve in input una matrice di matrici 
(una matmat) e un intero k e restituisce 1 se tra le matrici contenute
nella matmat ricevuta ce ne sono almeno k che contengono il numero k 
almeno k volte. Si consiglia di spezzare la soluzione del problema 
in più funzioni.

*/

#define N 20	
typedef int matrice[N][N];
typedef matrice matmat[N][N];

int i, j, cont , k = 0;

int f(matmat m,int k){
	int i,j,cont=0;

	//scorro la matrice di matrici
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			//l'elemto corrente è un amtrice NxN su cui valuto la funzione di test
			if(f1(m[i][j],k))
				// conto il numero di martrici che verificano la condizione
				cont++;

	//in base al numero di matrici restituisco 0 o 1
	if(cont>=k)
		return 1;
	else
		return 0;
}
int f1(matrice m, int k){
	int i,j,cont=0;
	//scorro tutta la matrice
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			//conto il numero di occorrenze di k
			if(m[i][j]==k)
				cont++;
	if(cont>=k)
		return 1;
	else
		return 0;
}


/*
Implementare una funzione C che riceve in input una matrice di matrici (una matmat)
e restituisce il massimo numero k per cui è vero che tra le matrici contenute nella
matmat ricevuta ce ne sono almeno k che contengono il numero k almeno k volte. 
Si consiglia di spezzare la soluzione del problema in più funzioni
*/

int f2(matmat m) {
	int i;
	//versione ottimista
	for(i=N*N;i>0;i--)
		if(f(m,i))
			return i;
	return 0;
}
