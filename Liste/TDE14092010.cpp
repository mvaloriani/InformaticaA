/*
Le telecamere di un parcheggio multilivello riconoscono
le targhe di ogni auto in ingresso. Se la targa è contenuta
nel file credito.txt (formattato come nel riquadro)
e il credito è di almeno 2,50 €, la funzione int checkin(char * targa)
restituisce 1, altrimenti restituisce 0
(e una botola risucchia l’auto in un pozzo senza fondo).
Si codifichi in C la funzione checkin

AC723YU 7.6
DR731TS 2.3
*/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int checkin(char* targa) {
	FILE * f;
	char plaque[8];
	float credit;
	if ((f = fopen("credito.txt", "r")) == NULL)
		return -1;
	while (fscanf(f, "%s%f", plaque, &credit) == 2) {
		if (strcmp(targa, plaque) == 0 && credit >= 2.50) {
			fclose(f);
			return 1;
		}
		//if (strcmp(targa, plaque) == 0) {
		//	if (credit >= 2.50) {
		//		fclose(f);
		//		return 1;
		//	}
		//	else {
		//		fclose(f);
		//		return 0;
		//	}
		//}

	}
	fclose(f);
	return 0;
}

//
//int checkin(char * targa) {
//	FILE * f;
//	char line[100], plaque[8];
//	float credit;
//	if ((f = fopen("credito.txt", "r")) == NULL)
//		return -1;
//	while (fgets(line, 100, f) != NULL) {
//		sscanf(line, "%s%f", plaque, &credit);
//		if (strcmp(targa, plaque) == 0 && credit >= 2.50) {
//			fclose(f);
//			return 1;
//		}
//	}
//	fclose(f);
//	return 0;
//}
//

/*
Le auto ammesse leggono su un display il piano
a cui devono recarsi, che è calcolato automaticamente
dal sistema come il primo che abbia almeno un posto libero.
La struttura dati del sistema è la seguente

dove ogni piano è pieno se il suo attributo
postiliberi vale 0 e vuoto se la sua lista macchine
è vuota.
Si codifichi in C la funzione
int assegnapiano(ListaDiListe L, char * targa),
che restituisce il numero del piano oppure -1
se non c’è posto.
La funzione alloca anche il nodo corrispondente
all’auto entrata

*/


typedef struct Car {
	char *targa;
	struct Car * next;
} Auto;
typedef Auto * Lista;

typedef struct Level {
	int postiliberi;
	Lista macchine;
	struct Level * next;
} Piano;
typedef Piano * ListaDiListe;


int assegnapianoI(ListaDiListe L, char * targa) {
	int p = 1;
	while (L != NULL && L->postiliberi == 0) {
		L = L->next;
		p++;
	}
	if (L == NULL)
		return -1;

	L->macchine = instesta(L->macchine, targa);
	(L->postiliberi)--;
	return p;
}

Lista instesta(Lista L, char * targa) {
	Lista punt;
	punt = (Lista)malloc(sizeof(Auto));
	punt->targa = (char *)malloc(8);    // 7 caratteri per la targa, uno per /0
	strcpy(punt->targa, targa);
	punt->next = L;
	return punt;
}

void instesta(Lista* L, char * targa) {
	Lista punt;
	punt = (Lista)malloc(sizeof(Auto));
	punt->targa = (char *)malloc(8);    // 7 caratteri per la targa, uno per /0
	strcpy(punt->targa, targa);
	punt->next = *L;
	L = punt;
}


int assegnapiano(ListaDiListe L, char * targa) {
	int p;
	if (L == NULL) return -1;
	if (L->postiliberi == 0) {
		p = assegnapiano(L->next, targa)
			if (p < 0) return -1;
			else return p + 1;
	}
	L->macchine = instesta(L->macchine, targa);
	(L->postiliberi)--;
	return 1;
}

int assegnapiano(ListaDiListe L, char * targa) {
	int p;
	if (L == NULL) return -1;
	if (L->postiliberi > 0) {
		L->macchine = instesta(L->macchine, targa);
		(L->postiliberi)--;
		return 1;
	}

	p = assegnapiano(L->next, targa)
		if (p < 0) return -1;
		else return p + 1;
}


/*
Si gestisca con la funzione ...checkout( ... )
l’uscita di un’auto dal parcheggio,
in modo da lasciare la struttura dati
in uno stato consistente. La funzione non si
occupa dell’addebito del costo del parcheggio.
Le soluzioni sostanzialmente ricorsive
ricevono un punto di bonus
*/

int find(Lista cars, char * targa) {
	if (cars == NULL) return 0;
	if (strcmp(cars->targa, targa) == 0) return 1;
	return find(cars->next, targa);
}

Lista remove(Lista cars, char * targa) {
	Lista punt;
	if (cars != NULL)
		if (strcmp(cars->targa, targa) == 0) {
			punt = cars->next;
			free(cars->targa);   // era stata allocata una stringa dinamica
			free(cars);
			return punt;
		}
		else {
			cars->next = remove(cars->next, targa);
			return cars;
		}
	else
		return cars;
}

Lista remove(Lista cars, char * targa) {
	Lista punt;
	if (cars == NULL) return NULL;

	if (strcmp(cars->targa, targa) == 0) {
		punt = cars->next;
		free(cars->targa);   // era stata allocata una stringa dinamica
		free(cars);
		return punt;
	}
	else {
		cars->next = remove(cars->next, targa);
		return cars;
	}

}

void checkout(ListaDiListe L, char * targa) {
	Lista cars;
	if (L == NULL) {
		printf("\n Nessuna traccia della macchina!\n");
		return;
	}
	if (find(L->macchine, targa) == 1) {
		L->macchine = remove(L->macchine, targa);
		(L->postiliberi)++;
		return;
	}
	else
		checkout(L->next, targa);
}
