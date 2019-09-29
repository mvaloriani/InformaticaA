#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Scrivere un programma C che stampi sullo standard output tutti 

i valori del triangolo di Tartaglia per un certo ordine N, utilizzando una funzione ricorsiva:  
int cobin(int n, int k); 
1                             n = 0
1    1                        n = 1
1    2    1                   n = 2
1    3    3    1              n = 3
1    4    6    4    1         n = 4
1    5   10  10   5   1       n = 5
1    6   15  20  15  6   1    n = 6
.................................................


 */







#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

#define N 5


int cobin(int n, int k) {
	if (n<k || n<0 || k<0) {
		printf("Errore\n");
			return 0;
	}

	if (k == 0 || k == n)
		return 1;
	else
		return cobin(n - 1, k - 1) + cobin(n - 1, k);
}

int main()
{

	int n, k;

	for (n = 0; n <= N; n++) {
		for (k = 0; k <= n; k++){
			printf("%d", cobin(n, k));
		}		
		printf("\n");
	}
	
	system("pause");

	return 0;
}

