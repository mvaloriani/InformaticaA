// Scrivere un programma C che legge un vettore di lunghezza arbitraria 
// e stampa 1 se il vettore contiene solo valori diversi, 0 altrimenti.

#include <stdio.h> 
#define n 15 

int main() {
	int i=0, j=0, t=0, si = 1;

	int v[n] = {0,1,0,1, 2,3,4};
	
	char input;

	/*usata per scambiare due elementi del vettore */
	printf("Inserire un vettore di interi di dimensione %d\n", n);
	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);


	//while (t<n)
	//{
	//	scanf("%c", &input);
	//	if (input != 'C') {
	//		scanf("%d", &v[i]);
	//		i++;
	//	}
	//}





	/* ometto codice lettura vettore */
	for (i = 0; (i < t - 1) && si!=0 ; i++) {

		for (j = i + 1; j < t && si != 0; j++) {
			if (v[i] == v[j]) {
				si = 0;
				
			}
		}
	}
	printf("%d\n", si);
	return 0;
}
