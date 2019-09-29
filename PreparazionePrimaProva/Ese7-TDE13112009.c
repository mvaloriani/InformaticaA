/*
Implementare una funzione C per il lancio di dadi. 
La funzione prenda in ingresso il numero di facce del dado, e
il numero di lanci che si vuole effettuare. La funzione simula
i lanci del dado e stampa a video quante volte è uscita ciascuna
faccia del dado.  Si faccia inoltre in modo che la stampa risulti
ordinata per numero di volte che è uscita una faccia in senso crescente.

Ad esempio, dopo 5 lanci con un dado a 6 facce in cui sono usciti i 
numeri (1, 1, 5, 4, 6), si stampi a video:
La faccia 4 è uscita 1 volta
La faccia 5 è uscita 1 volta
La faccia 6 è uscita 1 volte
La faccia 1 è uscita 2 volte

Attenzione, devono essere riportati sia il numero della faccia che il 
numero di volte che è uscita.

Si supponga esista e dunque si faccia uso della funzione 
int rand(int inf, int sup);
che restituisce un numero intero casuale compreso tra inf e sup.

*/

#define N 1000
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct { int valore;  int quanti; } faccia;

int myrand(int inf, int sup){
	srand(time(NULL));
	return(rand()%(sup-inf)+inf); 
}

void lancia(int lanci,int facce) {
	int i,j, val, flag; faccia dado[N], temp;
	
	//creo il dado
	for(i=0;i<facce;i++) {  
		dado[i].valore=i+1; dado[i].quanti=0; 
	}


	//genero i lanci
	for(i=0;i<lanci;i++) {
		val=myrand(1,facce);
		dado[val-1].quanti++;
	}

	//ordinamento
	for(i=0;i<facce-1;i++) {
		for(j=0;j<facce-1;j++) {
			if(dado[j].quanti>dado[j+1].quanti) {
				temp=dado[j];
				dado[j]=dado[j+1];
				dado[j+1]=temp;
			}
		}
	}

	//do	{
	//	flag = 0; //reiniziallizzo a zero il flag
	//
	//	for (int i = 0; i < facce; i++)
	//		if (dado[i].quanti > dado[i + 1].quanti){
	//			temp = dado[i];
	//			dado[i] = dado[i + 1];
	//			dado[i + 1] = temp;
	//
	//			flag = 1; //se avviene lo scambio modifico il valore del flag
	//		}
	//}
	//while (flag == 1);

è	/*
	//http://it.wikipedia.org/wiki/Insertion_sort
	faccia temp;
    for (int i = 1; i < facce; i++) {
		temp=dado[i];
        for (int j = i; j > 0 &&  dado[i].valore < dado[j - 1].valore; j--) {
            dado[j] = dado[j - 1];
        }
        dado[j] = temp;
    }
	*/

	//stampa
	for(i=0;i<facce;i++) {
		if(dado[i].quanti==1)
			printf("La faccia %d è uscita 1 volta", dado[i].valore);
		if(dado[i].quanti>1)
			printf("La faccia %d è uscita %d volte" , dado[i].valore, dado[i].quanti);
	}
}

