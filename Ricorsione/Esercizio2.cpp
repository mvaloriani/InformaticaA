#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Calcolo del massimo di un vettore con procedimento ricorsivo.

Si pensi di assegnare il primo elemento dell�array come massimo e 
confrontarlo con tutti gli altri cambiando il valore del massimo 
se questo � minore della cella corrente del vettore.

Detta N la lunghezza del vettore "array" �
Se N = 1           (caso base)
max = array[0]
Se N >= 2         (passo induttivo)
il massimo del vettore di N elementi (max) sar� uguale al risultato del 
confronto  tra array[0] e il massimo degli elementi del
sotto-vettore che che va da array[1] a array[N] (lungo N-1).

*/


#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema


#define len 10
typedef	int VETT[10];

int maxArray(int* arr, int n) {
	int maxsub;
	if (n == 1) return arr[0];//*arr
	if (n >= 2) {
		//maxsub = maxArray(&arr[1], n - 1);
		maxsub = maxArray(arr +1, n - 1);
		if (arr[0] > maxsub)
			//return arr[0];
			return *arr;
		else
			return maxsub;
	}
	printf("errore nei parametri di ingresso");
	return -1;  /* non raggiungibile */
}

int maxArray2(VETT arr, int n) {
	int maxsub;
	if (n == 1) return arr[0];
	if (n >= 2) {
		maxsub = maxArray2(&arr[1], n - 1);
		if (arr[0] > maxsub)
			return arr[0];
		else
			return maxsub;
	}
	return -1;  /* non raggiungibile */
}


int maxArray3(VETT array, int n, int i) {
	int maxsub;
	if (i == n) return array[n];
	else {
		maxsub = maxArray2(array, n, i+1);
		if (array[i] > maxsub)
			return array[i];
		else
			return maxsub;
	}
	return -1;  /* non raggiungibile */
}



int main()
{
	int test[len] = { 2, 3, 9, 2, 13, 4, 34, 2, 9, 5 };

	printf("\nMax = %d ", maxArray(test, len));
	
	
	VETT v = { 2, 3, 9, 2, 13, 4, 34, 2, 9, 5 };
	printf("\nMax = %d ", maxArray(v, len));

	printf("\nMax = %d ", maxArray2(test, len));

	//printf("\nMax = %d ", maxArray2(v, len));
	


	system("pause");

	return 0;
}

