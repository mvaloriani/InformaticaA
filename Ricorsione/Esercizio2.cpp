#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Calcolo del massimo di un vettore con procedimento ricorsivo.

Si pensi di assegnare il primo elemento dell’array come massimo e 
confrontarlo con tutti gli altri cambiando il valore del massimo 
se questo è minore della cella corrente del vettore.

Detta N la lunghezza del vettore "array"  
Se N = 1           (caso base)
max = array[0]
Se N >= 2         (passo induttivo)
il massimo del vettore di N elementi (max) sarà uguale al risultato del 
confronto  tra array[0] e il massimo degli elementi del
sotto-vettore che che va da array[1] a array[N] (lungo N-1).

*/


#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema


#define len 10
typedef	int VETT[10];

int maxArray(int *array, int n) {
	int maxsub;
	if (n == 1) return array[0];
	if (n >= 2) {
		maxsub = maxArray(&array[1], n - 1);
		if (array[0] > maxsub)
			return array[0];
		else
			return maxsub;
	}
	return -1;  /* non raggiungibile */
}

int maxArray2(VETT array, int n) {
	int maxsub;
	if (n == 1) return array[0];
	if (n >= 2) {
		maxsub = maxArray2(&array[1], n - 1);
		if (array[0] > maxsub)
			return array[0];
		else
			return maxsub;
	}
	return -1;  /* non raggiungibile */
}

int maxArray3(VETT v, int n) {
	int maxsub;
	if (n == 1) return v[0];
	if (n >= 2) {
		maxsub = maxArray3(&v[1], n - 1);
		if (array[0] > maxsub)
			return v[0];
		else
			return maxsub;
	}
	return -1;  /* non raggiungibile */
}


int main()
{
	int test[len] = { 2, 3, 9, 2, 13, 4, 34, 2, 9, 5 };

	printf("\nMax = %d ", maxArray(test, len));
	
	/*
	VETT v = { 2, 3, 9, 2, 13, 4, 34, 2, 9, 5 };
	printf("\nMax = %d ", maxArray(v, len));

	printf("\nMax = %d ", maxArray2(test, len));

	printf("\nMax = %d ", maxArray2(v, len));
	*/


	system("pause");

	return 0;
}

