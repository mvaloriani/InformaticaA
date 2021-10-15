#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Si consideri il seguente programma
#include <stdio.h>
… 
Si dica sinteticamente che funzioni svolgono f1
ed f2.
Le risposte che semplicemente spiegano il
codice passo per passo non saranno
considerate.
*/


#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

int f1(int a, int b) {		
	if (b == 0)
		return 1;
	return a * f1(a, b - 1);  

	/*
	b=0 1
	b=1 a
	b=2 a*a
	b=3 a*a*a
	*/
}
int f2(int a, int b) {
	int i;
	
	for (i = 0; f1(a, i) <= b; i++);
	
	return i - 1;

	/*
	2 2 -> 1
	2 3 -> 1
	2 4 -> 2
	2 5 -> 2
	2 6 -> 2
	2 7 -> 2
	2 8 -> 3
	*/
}
int main() {
	int i, a[3] = { 2,3,4 }, b[3] = { 8,30,256 };

	printf("_______________\n");

	for (i = 0; i < 3; i++)
		printf("%i ", f2(a[i], b[i]));

	printf("\n_______________\n");

	for (i = 0; i < 3; i++)
		printf("%i ", f1(a[i], f2(a[i], b[i])));

	printf("\n_______________\n");

	for (i = 0; i < 3; i++)
		printf("%i ", f2(a[i], f1(a[i], b[i])));

	system("pause");
}

