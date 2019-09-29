/*

SimpleScrabble è una versione del gioco Scrabble dove il valore 
delle parole dipende solo dalle lettere che le compongono. Ogni lettera
ha un valore (da 1 a 10) ed è disponibile in un certo numero di esemplari
(da 1 a 12). Il valore di una parola è la somma dei valori delle sue lettere.
Gli array valore e numero, definiti nell'ambiente globale come segue, indicano
il valore e il numero di esemplari disponibili di ognuna delle 26 lettere, 
in ordine alfabetico. Consideriamo per semplicità solo le lettere maiuscole.

int numero[26] = {9,2,2,4,12,2,3,2,9,1,1,4,2,6,8,2,1,6,4,6,4,2,2,1,2,1};
int valore[26] = {1,2,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

Ci sono quindi 9 A da 1 punto, 2 B da 2 pt, 2 C da 3 pt, 4 D da 2 pt, 12 E da 1 pt, …, 1 Z da 10 pt.
Una parola è valida se è di almeno 2 lettere ed è ottenibile con le lettere a
disposizione (CAB vale 3+1+2=6 pt, KARAOKE non è valida, perché disponiamo di una sola K).
Una funzione valida(...), che restituisce 1 se la parola è valida, 0 altrimenti
Una funzione punteggio(…) calcola e restituisce il valore della parola ricevuta
come parametro, assegnando 0 alle parole non valide.
Si codifichino in C le funzioni valida(…) e punteggio(...)



*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int numero[26] = { 9,2,2,4,12,2,3,2,9,1,1,4,2,6,8,2,1,6,4,6,4,2,2,1,2,1 };
int valore[26] = { 1,2,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10 };


int valida(char parola[]) {
	int i, p, cont, lun = strlen(parola);
	if (lun < 2)  return 0;
	for (i = 0; i<26; i++) {
		for (cont = 0, p = 0; p<lun; p++) 
			if (parola[p] == 'A' + i) cont++;
		if (cont > numero[i]) return 0;
	}
	return 1;
}

int punteggio(char parola[]) {
	int punt = 0, lun;
	if (valida(parola))
		for (lun = strlen(parola) - 1; lun >= 0; lun--) {
			char c = parola[lun];
			punt += valore[ c - 'A'];
		}
	return punt;
}



