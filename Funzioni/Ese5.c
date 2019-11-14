/*
Definire una struttura dati che descriva le 
squadre di un torneo di calcio.
Le squadre sono 6, di ogni squadra si devono 
memorizzare: matricola squadra,
nome, città e tutti giocatori come nome
e numero di maglia.
Quanta memoria occupa questa struttura?
Scrivere una funzione che riceve in ingresso
la struttura definita e stampa l’elenco dei
portieri titolari.

*/
#include <stdlib.h>
#include <stdio.h>

typedef struct {
	char cognome[10];
	int numero;
} giocatore;

typedef struct {
	int matricola;
	char nome[15];
	char città[10];
	giocatore formazione[11];
} squadra;

squadra torneo[6];


//6x(2 + 15 + 10 + 11 * (10+2)) = 954 bytes


void stampaPortieri(squadra sq[]) {
	int i, j;
	for (i = 0; i < 6; i++)
		for (j = 0; j < 11; j++)
			if (sq[i].formazione[j].numero == 1)
				printf("\n%s", sq[i].formazione[j].cognome);
}

void creatorneo(squadra sq[]) {
	int i, j;
	for (i = 0; i < 6; i++) {
		printf("Inserire matricola squadra\n");
		scanf("%d", sq[i].matricola);
		printf("Inserire nome squadra\n");
		scanf("%s", sq[i].nome);
		printf("Inserire citta' squadra\n");
		scanf("%s", sq[i].citta);
		for (j = 0; j < 11; j++) {
			printf("Inserire cognome giocatore\n");
			scanf("%s", sq[i].formazione[j].cognome);
			printf("Inserire numero maglia giocatore\n");
			scanf("%d", sq[i].formazione[j].numero);
		}
		printf("--------------------\n");
	}
}
