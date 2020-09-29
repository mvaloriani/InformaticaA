#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Si scriva un programma C che legga due serie di dati e 
li memorizzi in due vettori di strutture.

Nel primo vettore M (di dimensione 3) vengono memorizzati dati del tipo:
<matricola, nome, cognome>.
Si noti che la matricola identifica univocamente uno studente e
che non ci sono due strutture che 
contengono lo stesso numero di matricola. 

Nel secondo vettore V (di dimensione 7) vengono memorizzati dati del tipo:
<matricola, esame, voto>.
Possono esserci più record con lo stesso numero di matricola 
che denotano diversi esami fatti dallo stesso studente.

Si scriva un programma che tramite opportune procedure 
legga i dati in ingresso e li inserisca nei due vettori.

Successivamente per ogni studente con matricola X 
contenuto nel vettore M sommi tutti i suoi voti ottenuti
negli esami contenuti nel vettore V. 

*/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define DIMM 3
#define DIMV 7

typedef struct {
	int matricola;
	char Nome[20];
	char Cognome[20];
} studente;

typedef struct {
	int matricola;
	char esame[20];
	int voto;
} esami;

int main(){
	int i, j, S=0, trovato;
	
	esami V[DIMV];
	studente M[DIMM];

	//leggi gli studenti
	for(i=0;i<DIMM;i++){
		printf("Inserisci Matricola, Nome, Cognome\n");
		scanf("%d",&M[i].matricola);
		//scanf("%s",M[i].Nome);
		//scanf("%s", M[i].Cognome);
	

		trovato=0;

		for(j=0;j<i && trovato==0;j++){			
			// cerco eventuali duplicati
			if(M[i].matricola==M[j].matricola) {
				printf("Matricola doppia \n");
				i--; // riporto in dietro l'indice
				trovato=1;
			}
		}
		//matricola non duplicata
		if(trovato==0){
			scanf("%s",M[i].Nome);
			scanf("%s",M[i].Cognome); 
		}
	}

	//leggi esami
	for(i=0;i<DIMM;i++){
		printf("Inserisci Matricola, Esame, Voto\n");
		scanf("%d %s %d ",&V[i].matricola, V[i].esame,&V[i].voto);
	}


	//somma
	// ciclo su tutti gli studenti
	for(i=0;i < DIMM; i++) {
		S=0;
		//ciclo su tutti gli esami
		for(j=0; j < DIMV; j++){
			//se esame dello studente i sommo
			if(M[i].matricola == V[j].matricola){
				S=S+V[j].voto;			
			}		
		}	
		printf("Studente %s %s\n", M[i].Cognome, M[i].Nome);
		printf("Somma voti: %d\n",S);
	}
	system("pause");
}

