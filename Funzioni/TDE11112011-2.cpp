/*
I risultati della finale olimpica di nuoto della staffetta 4x100 
stile libero sono rappresentati mediante una matrice di dimensioni 4x8.
Ogni cella rappresenta il risultato di un singolo 
frazionista tramite la seguente struttura:
typedef struct { int min,sec,cent;} tempo;
typedef struct {char[15] nome,cognome,nazionalità;
tempo t; } frazione;
La matrice è dichiarata in questo modo:
typedef risultato frazione[4][8]
I risultati sono disposti nella matrice secondo la corsia 
(e.g. corsia 1 nella prima colonna)
Scrivere una funzione che riceve in ingresso la matrice 
che contiene il risultato e restituisce il numero della corsia vincente.
int corsiaVincente(risultato ris);
Scrivere una funzione che riceve in ingresso la matrice 
che contiene il risultato e una variabile che contiene il
record mondiale di staffetta e che restituisce 1 se il record 
mondiale è stato battuto, 0 altrimenti.
int recordBattuto(risultato ris, tempo record);

*/
#include <stdlib.h>
#include <stdio.h>

typedef struct { int min, sec, cent; } tempo;

typedef struct {

	tempo t;
	char[15] nome;
} frazione;


typedef frazione risultato[4][8];





long converti(tempo t) {
	return t.min * 6000 + t.sec * 100 + cent;
}
long calcolaCorsia(risultato ris, int k) {
	int i, tot = 0;
	for (i = 0; i<4; i++) {
		tot += converti(ris[i][k]);
	}
	return tot;
}

int corsiaVincente(risultato ris) {
	int i, min, corrente, imin = 0;
	min == calcolaCorsia(ris, 0);
	for (i = 0; i<8; i++) {
		corrente = calcolaCorsia(ris, i);
		if (corrente<min) {
			min = corrente; imin = i;
		}
	}
	return imin + 1;
}


int recordBattuto(risultato ris, tempo record) {
	int v;
	v = corsiaVincente(ris);
	if (calcolaCorsia(ris, v)<converti(record))
		return 1;
	else
		return 0;
}
