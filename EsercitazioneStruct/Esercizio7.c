#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Si scriva un programma C per la gestione di una scuola di ballo. 
Ogni classe consiste di un insieme di persone e di due istruttori. 
Ogni persona ha un nome, un cognome, un sesso e un�et�.

Si definiscano le strutture dati necessarie allo sviluppo del programma (strutture, array, ecc.)
Si implementi un frammento di codice che partendo da una struttura di tipo �classe� 
stampa l�et� media degli studenti di sesso maschile

*/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define N 100

typedef struct { 
	char nome[N], cognome[N];
	char s;
	int eta; 
} persona;

typedef struct {
	persona studenti[N];
	persona istruttori[2];
	int nIscritti; 
} classe;

//typedef struct {	
//	classe corsi[N];
//	int nCorsi;
//} scuola;

int main(){
	classe c;
	// codice di inizializzazione classe c ...

	float media=0.0;
	int i=0, tot=0, quanti=0;
	
	//ciclo sugli inscritti
	for(i=0;i<c.nIscritti;i++) {
		// se � uomo sommo l'et� e conto il numrto di
		if(c.studenti[i].s=='m'){
			tot+= c.studenti[i].eta;
			quanti++;
		}
	}

	if(quanti==0)
		return -1.0;

	media=(float)tot/quanti;

	printf("%d",media);
	system("pause");

	return 0;

}