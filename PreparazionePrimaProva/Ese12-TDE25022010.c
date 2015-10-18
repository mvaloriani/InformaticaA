/*
typedef struct Intv { unsigned small int r, c; } Casella;
typedef Casella TappetoElastico[10][10];
Pare che tra le discipline degli ottocenteschi “circhi delle pulci” non ci fosse
il tappeto elastico (non in quello del Prof. Heckler, almeno). Ma avrebbe potuto
funzionare così: la pulce salta sulla prima cella (0,0) del tappeto elastico (quadrato),
atterrandovi legge le coordinate (riga e colonna) della prossima cella su cui saltare,
e da lì continua a saltare, ogni volta leggendo le coordinate della cella successiva verso
cui saltare. Se/quando le coordinate lette indicano un punto esterno al tappeto, la pulce scende (applausi)
Si implementino le seguenti funzioni in C e si spieghi brevemente come funzionano gli algoritmi usati.
... ciclico(...) che riceve in input un tappeto elastico e restituisce 1 se esso
obbliga a saltare indefinitamente, 0 se invece a un certo punto la pulce potrà scendere
... contasalti(...) che riceve un tappeto elastico e misura il numero di salti che
la pulce compie prima di scendere (se il tappeto non è ciclico), oppure -1
... dicoppia(...) che controlla se un tappeto è adatto all’esibizione di coppia:
una seconda pulce inizia a saltare dalla casella (9,9) contemporaneamente alla prima pulce,
ed esse cotinuano a saltare e atterrare in perfetta sincronia fino a uscire assieme dal tappeto
senza mai “scontrarsi” – cioè atterrare contemporaneamente sulla stessa casella
*/

#include <stdio.h>

typedef struct Intv {
	unsigned small;
	int r, c;
} Casella;

typedef Casella TappetoElastico[10][10];

void clean(TappetoElastico tappeto){
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			tappeto[i][j].small = 0;
		}
	}
}

int saltoFuori(Casella casella){

	if (casella.c >= 0 && casella.c < 10 &&
		casella.r >= 0 && casella.r < 10)
		return 1;
	else
		return 0;
}

int ciclico(TappetoElastico tappeto){

	clean(tappeto);

	int c = 0, c1 = 0 r = 0, ciclo = 0;
	while (saltoFuori(tappeto[r][c]) &&
		ciclo == 0){

		ciclo = tappeto[r][c].small;
		tappeto[r][c].small = 1;
		c1 = tappeto[r][c].c;
		r = tappeto[r][c].r;
		c = c1;
	}

	return ciclo;
}

int contaSalti(TappetoElastico tappeto){
	int salti = 0;
	if (ciclico(tappeto))
		return -1;
	else
	{
		int r = 0, c = 0, c1;
		do{
			salti++;
			c1 = tappeto[r][c].c;
			r = tappeto[r][c].r;
			c = c1;
		} while (saltoFuori(tappeto[r][c]));
	}
	return salti;
}

int dicoppia(TappetoElastico tappeto){
	if (ciclico2(tappeto, tappeto[0][0]) || ciclico2(tappeto, tappeto[9][9]))
		return 0;
	else
		return contaSalti2(tappeto, tappeto[0][0]) == contaSalti2(tappeto, tappeto[9][9]) ? 1 : 0;
}





int ciclico2(TappetoElastico tappeto, Casella casella){

	clean(tappeto);
	int c = casella.c, c1,  r = casella.r, ciclo = 0;
	while (saltoFuori(tappeto[r][c]) &&
		ciclo == 0){

		ciclo = tappeto[r][c].small;
		tappeto[r][c].small = 1;
		c1 = tappeto[r][c].c;
		c = c1;
		r = tappeto[r][c].r;
	}

	return ciclo;
}
int contaSalti2(TappetoElastico tappeto, Casella casella){
	int salti = 0;
	if (ciclico(tappeto))
		return -1;
	else
	{
		int r = casella.r, c = casella.c;
		do{
			salti++;
			c = tappeto[r][c].c;
			r = tappeto[r][c].r;
		} while (saltoFuori(tappeto[r][c]));
	}
	return salti;
}

int ciclico3(TappetoElastico tappeto, Casella casella){
	clean(tappeto);
	return ciclicoRicorsivo(tappeto, casella);
}
int ciclicoRicorsivo(TappetoElastico tappeto, Casella casella){
	if (saltoFuori(casella))
		return 0;

	if (tappeto[casella.r][casella.c].small == 1)
		return 1;

	return ciclicoRicorsivo(tappeto, tappeto[casella.r][casella.c]);
}

int contaSalti3(TappetoElastico tappeto, Casella casella){

	if (ciclico2(tappeto, casella))
		return -1;
	else
		return	contaSaltiRicorsivo(tappeto, casella);

}
int contaSaltiRicorsivo(TappetoElastico tappeto, Casella casella){

	if (saltoFuori(casella))
		return 1;

	return 1 + contaSaltiRicorsivo(tappeto, tappeto[casella.r][casella.c]);
}


