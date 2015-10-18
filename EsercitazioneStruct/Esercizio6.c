/*
Si considerino le seguenti dichiarazioni di tipi e variabili,
che definiscono le strutture dati per rappresentare dei rilevamenti
meteorologici effettuati per 30 comuni lombardi nell’intero anno 2009

Scrivere un frammento di codice, definendo eventuali variabili aggiuntive,
che trovi tutte le città che nel mese di dicembre hanno registrato almeno
un rilievo in cui il livello di pioggia caduta è superiore a quello memorizzato
nella variabile sogliaP. Per ognuna di tali città si visualizzi su un’unica riga il nome
e la media della quantità di pioggia caduta calcolata sull’intero anno. 

*/


#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef struct { 	  
	unsigned int giorno; /* tra 1 e 31 */
	unsigned int mese; /* tra 1 e 12 */
	float livelloP; /* pioggia caduta */
} rilievo;

typedef struct 	{ 	
	char comune[20]; /*nome del comune*/
	rilievo rilievi[365]; /* max 365 rilievi, non è detto che i     
						  /* rilievi abbiano cadenza giornaliera */
	int nRilievi; /* numero di rilievi effettivamente 
				  /* registrati in rilievi */
} rilieviComune; /* dati monitorati nell’anno per un singolo comune */

typedef rilieviComune rilieviGlobali[30]; /* dati monitorati nell’anno 
										  /* per tutti i 30 comuni */
rilieviGlobali dg;
float sogliaP;  


/* Si assuma che le variabili sogliaP e dg siano state inizializzate attraverso istruzioni qui non mostrate */

int main(){
	int i,j,n,trovato;
	float totaleP, media, totaleDicembre;

	//scorro tutti i comuni
	for (i=0; i<30; i++) {
		// salvo localmennte il numero di rilevazioni nel comune i
		n=dg[i].nRilievi;

		//azzero le variabili di controllo
		trovato=0;
		totaleP=0.0;

		//scorro tutte le rilevazioni delcomune i
		for (j=0; j<n; j++) {
			//sommo i rilievi
			totaleP += dg[i].rilievi[j].livelloP;

			// a dicembre è piovuto più della sogliaP
			if ((dg[i].rilievi[j].mese==12) && (dg[i].rilievi[j].livelloP > sogliaP)){
				trovato=1;
				

			}
			//if(dg[i].rilievi[j].mese==12){
			//	totaleDicembre += dg[i].rilievi[j].livelloP;
			//	if(totaleDicembre>sogliaP){
			//		trovato=1;
			//	}
			//}
		}

		// se il vincolo è rispostato
		if (trovato) {
			// calcolo a media
			media = totaleP/n;
			// stampo a video
			printf("Il comune di %s nel 2009 ha registrato un livello medio di precipitazioni di %f",
				dg[i].comune, media); 
		} 
	}

}