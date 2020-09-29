#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Si consideri il seguente programma C, 
completando la definizione di MATR con la propria matricola


*/



#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema
#include <string.h>  // include libreria per gstione stringhe


#define MATR "623372"   	/* Ad esempio "623372" */
#define CIFRE "0987654321"

void f(int);
void g(char *, char *);

int main() {
	f(3);

	printf("\n");
	system("pause");
	return 0;
}

void f(int i) {
	char mat[7] = MATR;
	char cif[11] = CIFRE;
	mat[0] = mat[1] = mat[2] = 'A' + i - 3;

	if (mat[i] != '\0')
		g(mat + i, cif);

	return;
}

void g(char * mat, char * cif) {
	char * start = NULL;
	if (*mat != '\0') {
		start = cif;
		while (*cif != *mat)
			cif++;
		printf("+ %c%d +",*mat,cif-start);
			f(7 - strlen(mat));
	}
	return;
}

