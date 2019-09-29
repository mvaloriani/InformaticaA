/*
Dato il tipo
typedef struct { int V[20];  int C;     } STR; 
Scrivere una funzione con un parametro formale X di 
tipo STR e un parametro formale MATR
di tipo matrice 20x20 interi. 

La funzione considera i primi C elementi contenuti 
nel campo V di X e restituisce
la somma di quelli tra loro che sono multipli di
almeno tre elementi della matrice MATR. 
Si supponga che il valore del campo C  sia sempre 
compreso tra 0 e 19 (estremi inclusi). 
Si utilizzino opportune funzioni ausiliarie 
per dividere il problema 
in sottoproblemi più semplici.
*/



#include <stdio.h> 
typedef struct { int V[20];  int C;     } STR; 
typedef  int MATR[20][20];

int contaSMseMag3(int x, MATR m){
	int i,j,cont=0;
	for (i = 0; i < 20; i++) {
		for (j = 0; j < 20; j++)
			if (m[i][j] != 0 && x%m[i][j] == 0) {
				cont++;
				if (cont >= 3)
					return 1;
			}
	}

		return 0;
}
int f(STR x, MATR m){
	int i,s=0;
	for(i=0;i<x.C;i++)
		if(contaSMseMag3(x.V[i], m)==1)
			s= s+ x.V[i];
	return s;
}
