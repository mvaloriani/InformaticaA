#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Scrivere un programma in linguaggio C che, letti tre numeri interi a, b, c
dallo standard input, stampi a terminale la sequenza dei tre numeri in
ordine monotono non decrescente.
Esempio: a = 10, b = 7, c = 9 deve dare in uscita 7 9 10.

*/


#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema


int main()
{
	// Leggo 3 valori
	int a, b, c;


	printf("\n Inserisci il numero a: ");
	scanf("%d", &a);
	printf("\n Inserisci il numero b: ");
	scanf("%d", &b);
	printf("\n Inserisci il numero c: ");
	scanf("%d", &c);

	//Solution 1
	//if (a < b) {
	//	if (b < c) { printf("\n L'ordine voluto e': %d, %d, %d\n", a, b, c); }
	//	else {
	//		if (a < c) {
	//			printf("\n L'ordine voluto e': %d, %d, %d\n", a, c, b); 

	//		}
	//		else { 
	//			printf("\n L'ordine voluto e': %d, %d, %d\n", c, a, b); 
	//		}
	//	}
	//}
	//else {
	//	if (c < b) { printf("\n L'ordine voluto e': %d, %d, %d\n", c, b, a); }
	//	else {
	//		if (a < c) {
	//			printf("\n L'ordine voluto e': %d, %d, %d\n", b, a, c); 
	//		}
	//		else { 
	//			printf("\n L'ordine voluto e': %d, %d, %d \n", b, c, a); 
	//		}
	//	}
	//}

	////Solution 2
	int temp;
	if (a > b) { temp = a;    a = b;    b = temp; }
	if (a > c) { temp = a;    a = c;    c = temp; }
	if (b > c) {
		temp = b;
		b = c;
		c = temp;
	}
	printf("\n L'ordine voluto è: %d, %d, %d \n", a, b, c);

	system("pause");

	return 0;
}

