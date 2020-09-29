#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Si scriva un programma C gestisce i dati di cantanti rappresentati 
con questa struttura dati:
typedef struct {
char cognome[N];
char nome[N];
int dischi;
} Tabella;
Il programma deve gestire il menù
Che operazione vuoi eseguire?
1. Inserisci nuovo record
2. Ordina record
3. Visualizza record
4. Esci

*/


#include <stdio.h> 
#include <string.h>
#include <stdlib.h>


#define RIGHE 5
#define N 15

//definizione di un nuovo tipo
typedef struct {
	char cognome[N];
	char nome[N];
	int dischi;
} Tabella;

int main() {
	int i, j, record_inseriti=0, operazione, uscita=4;
	Tabella tabella[RIGHE], temp;//temp usato per ordinare
	
	do {
		printf("Che operazione vuoi eseguire? ");
		printf("\n\t 1. Inserisci nuovo record\n\t 2. Ordina record");
		printf("\n\t 3. Visualizza record\n\t 4. Esci\n\t ");
		scanf("%d", &operazione);
		getchar(); //scarta il carattere di a capo

		switch(operazione) {
		case 1:
			if(record_inseriti == RIGHE) 
				printf("Hai inserito il numero massimo di record all'interno della tabella.");
			else {
				printf("\nInserisci il cognome dell'artista: ");
				scanf("%s",tabella[record_inseriti].cognome);
				printf("Inserisci il nome dell'artista: ");
				scanf("%s",tabella[record_inseriti].nome);
				printf("Inserisci il numero di dischi venduti: ");
				scanf("%d", &tabella[record_inseriti].dischi);
				getchar();//consuma l'invio
				record_inseriti++;
			}            
			break;
		case 2:
			for(i = 0; i < record_inseriti - 1; i++) {
				for(j = i+1; j < record_inseriti; j++) {
					if(tabella[i].dischi < tabella[j].dischi) {
						temp = tabella[i];
						tabella[i] = tabella[j];
						tabella[j] = temp;
					}
				}
			}
			printf("\nVettore ordinato secondo ordinamento decrescente dei dischi");
			break;
		case 3:
			if(record_inserit==0)
				printf("\nNon sono presenti record all'interno della tabella.");
			else {
				printf("\n%s %s %s", "Nome", "Cognome", "Dischi");
				for(i = 0; i < record_inseriti; i++) {
					printf("\n%s %s %d",tabella[i].cognome,tabella[i].nome,tabella[i].dischi);
				}
				break;
		case 4:
			break;
		default:
			printf("\nHai effettuato una scelta non valida");
			}

			if(operazione != uscita) {
				printf("\n\nPremi INVIO per continuare.");
				getchar();
			}
		}
	} while(operazione != uscita);

	printf("\nPremi INVIO per uscire.");
	getchar();
	return 0;
}
