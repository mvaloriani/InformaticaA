#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Dato un file di testo chiamato dati.txt già esistente contenente uno 
per riga valori che rappresentano numeri relativi, scrivere un 
programma in linguaggio C in cui si dichiarino due struct ST1 e ST2
ciascuna con due campi a e b di tipo int e che effettua le seguenti operazioni: 
scrive su video quanti valori contiene il file dati.txt;
pone nel campo a di ST1 il più grande valore contenuto in dati.txt;
pone nel campo b di ST1 il più piccolo valore contenuto in dati.txt;
pone nel campo a di ST2 la differenza fra il più grande e il più piccolo valore contenuto in dati.txt;
pone nel campo b di ST2 il prodotto fra il più grande e il più piccolo valore contenuto in dati.txt.

*/


#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

typedef struct { int a, b; } ST;


int main()
{
	ST ST1, ST2;     FILE *f;     int val;

	//Apro il file in modelità lettura
	f = fopen("dati.txt", "r");

	if (f == NULL) 
		exit(-1);

	if (fscanf(f, "%d", &ST1.a) != EOF) {
		ST1.b = ST1.a;
		do {
			if (fscanf(f, "%d", &val) != EOF) {
				//cerco il massimo
				if (val > ST1.a) { 
					ST1.a = val; 
				}
				//cerco il minimo
				else if (val < ST1.b) {
					ST1.b = val; 
				}
			}
		} while (feof(f) == 0 && ferror(f) == 0);
		
		//while (feof(f)!=1)
		//{
		//	fscanf(f, "%d", &val);
		//	//cerco il massimo
		//	if (val > ST1.a) {
		//		ST1.a = val;
		//	}
		//	//cerco il minimo
		//	else if (val < ST1.b) {
		//		ST1.b = val;
		//	}
		//}

		// calcolo la differenza tra min e max
		ST2.a = ST1.a - ST1.b;  
		// calcolo il prodotto
		ST2.b = ST1.a * ST1.b;
		printf("%d %d\n %d %d\n", ST1.a, ST1.b, ST2.a, ST2.b);
	}
	fclose(f);

	system("pause");

	return 0;
}

