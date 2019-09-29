#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Dato un file di testo chiamato dati.txt già
esistente contenente uno per riga valori che
rappresentano numeri relativi, scrivere un programma
in linguaggio C in cui si dichiarino due file F1 e F2
che esternamente si chiameranno rispettivamente
dati1.txt e dati2.txt e effettua le seguenti operazioni: 
- scrive quanti valori contiene il file dati.txt;
- pone in dati1.txt gli elementi di dati.txt divisibili per 7;
- pone in dati2.txt gli elementi di dati.txt divisibili per 5;
- scrive su video quanti valori contiene il file dati1.txt;
- scrive su video quanti valori contiene il file dati2.txt;

*/


#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema

typedef struct { int a, b; } ST;


int main()
{
	FILE *f, *f1, *f2;
	int val, cont = 0, cont7 = 0, cont5 = 0;

	f = fopen("dati.txt", "r");
	f1 = fopen("dati1.txt", "w");
	f2 = fopen("dati2.txt", "w");

	if (f == NULL || f1 == NULL || f2 == NULL)
		exit(-1);

	//scorro tutto il file
	while (fscanf(f, "%d", &val) != EOF) {
		cont++;
		//verifico se divisibile per 7
		if (val % 7 == 0) {
			cont7++;
			fprintf(f1, "%d\n", val);
		}
		//verifico se divisibile per 5
		if (val % 5 == 0) {
			cont5++;
			fprintf(f2, "%d\n", val);
		}
	}

	printf("%d %d %d\n", cont, cont7, cont5);

	fclose(f);
	fclose(f1);
	fclose(f2);


	system("pause");

	return 0;
}



typedef struct { int cont, contval, operazioneComppletata; } RET;
RET F(int div, FILE *fileDestinazione, FILE *fileOrigine) {
	RET valreturn;
	int cont, contval, val;

	if (fileDestinazione == NULL || fileOrigine == NULL) {
		valreturn.operazioneComppletata = 0;
		return valreturn;
	}



	//scorro tutto il file
	while (fscanf(fileOrigine, "%d", &val) != EOF) {
		cont++;
		//verifico se divisibile per 7
		if (val % div == 0) {
			contval++;
			fprintf(fileOrigine, "%d\n", val);
		}
	}
	valreturn.cont = cont;
	valreturn.contval = contval;
	valreturn.operazioneComppletata = 1;

	fclose(fileDestinazione);
	fclose(fileOrigine);
	return valreturn;
}
