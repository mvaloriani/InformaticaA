#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Definire tipi di dato per un PRA:
Il tipo dati Motoveicolo rappresenta i dati di un motoveicolo.
Questi dati si compongono di:
-targa del motoveicolo (7 lettere)
-marca del motoveicolo (massimo 15 caratteri),
-modello (massimo  20  caratteri),
-cilindrata  (in  cc),
-potenza  (in  kW),
-categoria  (massimo 16 caratteri).


Supponiamo un char occupi 1 byte, un int 2 byte e un float 4 byte
Quanto occupano le strutture dati in tutto?

*/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef struct {
	char targa[7];
	char marca[15];
	char modello[20];
	int cilindrata;
	float potenza;
	char categoria[16];
} Motoveicolo;

/*
7+15+20+2+4+16=64
*/


/*
Il tipo dati Proprietario  rappresenta  i  dati  di  una  persona
(il  proprietario  del motoveicolo):
nome  (massimo 30  caratteri),
cognome (massimo 40 caratteri),
codice  fiscale (16 caratteri).
Il tipo dati VocePRA  rappresenta  una  singola  voce  nel  registro
automobilistico;
una  voce  si compone  di  2  elementi: i  dati  del  proprietario
del motoveicolo  ed  i  dati  del motoveicolo stesso.

*/


typedef struct {
	char nome[30];
	char cognome[40];
	char codice_fiscale[16];
} Proprietario;

typedef struct {
	Motoveicolo motoveicolo;
	Proprietario proprietario;
} VocePRA;


/*
Il tipo dati PRA rappresenta un tipo adatto a contenere i dati di un PRA.
Questo tipo di dati è un elenco di voci del PRA
(si suppone che un PRA non possa contenere più di 10.000 elementi),
più un contatore che dice quante voci sono effettivamente presenti nel PRA.
*/

typedef struct {
	VocePRA elementi[10000];
	int n_elementi;
} PRA;


/*

Scrivere un programma che estrare l’automobilista con l’auto
con cilindrata maggiore

Scrivere un programma che estrare l’automobilista con la somma
delle cilindrate delle sue auto maggiore

*/



int main() {
	PRA p; int maxcc = 0; int i, j, k; int currentcc = 0; int loStesso = 0;
	Proprietario pr;

	for (i = 0; i < p.n_elementi; i++) {		
		if (p.elementi[i].motoveicolo.cilindrata > maxcc) {
			maxcc = p.elementi[i].motoveicolo.cilindrata;
			pr = p.elementi[i].proprietario;
		}
	}

	for (i = 0; i < p.n_elementi; i++) {
		currentcc = 0;
		// trovo la somma delle cilindrate per un Utente X
		for (j = 0; j < p.n_elementi; j++) {

			//if(p.elementi[i].proprietario==p.elementi[j].proprietario)

			loStesso = 1;
			for (k = 0; k < 16 && loStesso == 1; k++) {
				if (p.elementi[i].proprietario.codice_fiscale[k] !=
					p.elementi[j].proprietario.codice_fiscale[k]) {
					loStesso = 0;
				}
			}
			/*if(strcmp(p.elementi[i].proprietario.codice_fiscale,
			p.elementi[j].proprietario.codice_fiscale)==0)*/

			if (loStesso == 1) // non è mai diventato 0, quindi nessuna cifra del codice fiscale è diversa
				currentcc += p.elementi[j].motoveicolo.cilindrata;

		}
		
		if (currentcc > maxcc) {
			maxcc = currentcc;
			pr = p.elementi[i].proprietario;
		}
	}
}