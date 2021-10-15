#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Scrivere un programma che dato un numero N>0 
di valori da inserire da tastiera, stampi a 
video il massimo della sequenza inserita e la 
posizione in cui tale valore è stato inserito.
Supponiamo, per semplicità, che non ci siano duplicati
Esempio: N=5 sequenza: 3, 2, 9, 5, 1
Max=9 Pos=3

*/



#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

int main() {
	int N, elemento, max, posmax, i = 1;
	printf("Inserire numero di valori: "); 
	scanf("%d", &N);

	if (N>0) {
		printf("Inserire il primo valore:");
		scanf("%d", &elemento);
		max = elemento;
		posmax = i;
		while (i<N) {
			printf("Inserire un altro valore:"); 
			scanf("%d", &elemento);
			i = i + 1;
			if (elemento>=max) {
				max = elemento; 
				posmax = i; }
		}

		////Soluzione 2
		max = 0; // uso il il piccolo degli int / inizializzo al primo ciclo
		i = 0;
		do
		{
			printf("Inserire un valore:");
			scanf("%d", &elemento);
			i = i + 1;
			if (elemento>max) { max = elemento; posmax = i; }
		} while (i<N);

		printf("Il massimo e': %d\n", max);
		printf("La posizione del massimo e': %d\n", posmax);
	}
	else
		printf("Il valore di N non e' accettabile\n");

	system("pause");
	return 0;
}
