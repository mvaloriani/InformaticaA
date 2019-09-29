/*
Si scriva un programma C che all'interno del main consenta di inizializzare da tastiera un vettore di interi di lunghezza massima pari a 20. 
La lunghezza effettiva della sequenza acquisita è stabilita dall'utente (ad esempio, acquisendo da tastiera il valore di una variabile n). 
Il programma dovrà stampare il vettore, scorrere il vettore e stampare gli elementi del vettore che hanno un numero pari nella posizione immediatamente precedente alla propria.
Per esempio, se l'utente sceglie di inserire 10 valori, avendo letto in input e memorizzato nell'array i seguenti interi :
1 2 3 4 5 6 7 8 9 0
Il programma produrrà il seguente output :
1 2 3 4 5 6 7 8 9 0
3 5 7 9

*/

# include <stdio.h> 
# define MAXDIM 20 

int main() {
	int vet[MAXDIM], i = 0, valore;

	do { /* leggo la lunghezza che deve essere accettabile */
		printf("\nInserisci un numero intero \n");
		scanf("%d", &valore);
	} while (valore<0 || valore>MAXDIM);
	printf("\n Inserisci una sequenza di %d interi:\n", valore);
	for (i = 0; i<valore; i++) {
		scanf("%d", &vet[i]);
	}
	printf("\n La sequenza di %d interi inserita e':\n", valore);
	for (i = 0; i<valore; i++) {
		printf("%d ", vet[i]);
	}
	printf("Stampo elementi con un pari nella posizione precedente"); 
		for (i = 1; i<valore; i++) /* Il primo elemento non ha precedente*/
			if (vet[i - 1] % 2 == 0)
				printf("%d ", vet[i]);
	return 0;
}
