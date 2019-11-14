#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
La FPF Inc. (Fictional Pigs Farm) si dedica da sempre
all'allevamento di maialini da palcoscenico più o meno famosi,
e conserva i dati dei suoi piccoli divi in un vettore 
(di cui solo una parte è utilizzata, pari a num_maialini:
gli elementi di indice da num_maialini a N-1 non sono usati):

typedef struct { int giorno; int mese; int anno; } Data;
typedef struct { char nome[20]; Data datanascita; float peso; int popolarita; } Maialino;
typedef struct { int num_maialini; Maialino pigs[N]; } Allevamento;

I maialini non sono elencati nell'Allevamento in un alcun ordine 
particolare, ma la ditta necessita di scandirli in ordine di 
ognuna delle loro caratteristiche (
cioè in ordine di nome, di data di nascita, di popolarità,
e di peso corporeo), a seconda delle diverse necessità applicative
(rispettivamente: appello nominale, trattamento pensionistico, 
merchandising, utilizzo culinario qualora la popolarità
cali eccessivamente).

A tal fine, si utilizzano quattro distinti vettori di puntatori, 
in cui ogni puntatore punta a un maialino specifico.

In questo modo si rappresentano quattro diversi ordinamenti
indipendenti degli elementi di uno stesso insieme (di maiali) 
senza dover replicare tutti i dati ad essi relativi, 
ma replicando solo i puntatori:

Maialino * ord_alfabetico[N], ord_data[N], ord_pop[N], ord_peso[N];

Si codifichi un programma che costruisca correttamente
i quattro vettori di puntatori. 

Il programma deve dapprima stampare tutti i dati dei maialini,
nell'ordine in cui si trovano nell'allevamento, 
poi ordinare i puntatori nei vari vettori, 
e visualizzare i maialini secondo i diversi ordinamenti. 

Si utilizzi (anche) la funzione 

int confronta( Data d1, Data d2 ) che restituisce 0 se 
le due date sono uguali, 1 se in ordine cronologico crescente,
-1 se in ordine inverso.

*/


#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define N 20 

typedef struct { int giorno; int mese; int anno; } Data;
typedef struct { char nome[20]; 
				Data datanascita; 
				float peso; int popolarita; } Maialino;

typedef struct { int num_maialini; 
				Maialino pigs[N]; } Allevamento;

Maialino * ord_alfabetico[N];
Maialino *ord_data[N];
Maialino *ord_pop[N];
Maialino *ord_peso[N];


void inizializza(Allevamento* all,
			Maialino* ord_alfabetico[],
			Maialino* ord_data[],
			Maialino* ord_pop[],
			Maialino* ord_peso[]) {

	for (int i = 0; i < all->num_maialini; i++) {
		ord_alfabetico[i] =  &(all->pigs[i]);
		ord_data[i] = &(all->pigs[i]);
		ord_pop[i] = &(all->pigs[i]);
		ord_peso[i] = &(all->pigs[i]);
	}
	return;
}

int confronta(Data d1, Data d2) {
	if (d1.anno > d2.anno) return -1;
	if (d1.anno < d2.anno) return 1;
	if (d1.mese > d2.mese) return -1;
	if (d1.mese < d2.mese) return 1;
	if (d1.giorno > d2.giorno) return -1;
	if (d1.giorno < d2.giorno) return 1;

	return 0;

	//int peso1 = d1.anno * 10000 + d1.mese*100 + d1.giorno;
	//int peso2 = d2.anno * 10000 + d2.mese*100 + d2.giorno;
	//if (peso1 - peso2 == 0) return 0;
	//return peso1 > peso2 ? -1 : 1;	
}

void sort(Maialino* ord[], int length, int tipoordonamento) {
	Maialino* temp;

	bool swap=false;

	for (int i = 0; i < length-1; i++)
	{
		for (int j = 0; j < length-i-1; j++)
		{
			//peso
			if (tipoordonamento = 1 && ord[j]->peso >= ord[j+1]->peso) {
				swap=true;
			}
			//popolarita
			if (tipoordonamento = 2 && ord[j]->popolarita >= ord[j+1]->popolarita) {
				swap=true;
			}
			//data
			if (tipoordonamento = 3 && 
				confronta(ord[j]->datanascita, ord[j+1]->datanascita)==-1) {
				swap = true;
			}
			//alfabetico
			if (tipoordonamento = 4 && strcmp(ord[j]->nome, ord[j+1]->nome) == -1) {
				swap = true;
			}

			if (swap) {
				//swap
				temp = ord[j];
				ord[j] = ord[j+1];
				ord[j+1] = temp;
			}

			swap = false;
		}
	}
}


void stampaMaialini(Maialino* ord[], int dimensione) {
	for (int i = 0; i < dimensione; i++)
	{
		printf("Peso: %d, Popolarita: %d", ord[i]->peso, ord[i]->popolarita);
	}
}

int main() {
	Allevamento all;
	inizializza(&all, ord_alfabetico, ord_data, ord_pop, ord_peso);

	stampaMaialini(ord_alfabetico, all.num_maialini);

	//sort
	sort(ord_alfabetico, all.num_maialini, 4);
	sort(ord_data, all.num_maialini, 3);
	sort(ord_pop, all.num_maialini, 2);
	sort(ord_peso, all.num_maialini, 1);

	//print
	stampaMaialini(ord_alfabetico, all.num_maialini);
	stampaMaialini(ord_data, all.num_maialini);
	stampaMaialini(ord_pop, all.num_maialini);
	stampaMaialini(ord_peso, all.num_maialini);

	}