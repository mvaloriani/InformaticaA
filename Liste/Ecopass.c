#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

/*
Si consideri la seguente definizione:
	typedef struct Elem { char * targa; struct Elem * next;  } Auto;
	typedef Auto * Lista;
Il sistema di controllo del traffico di una città registra gli accessi delle auto al centro. 
Ad ogni passaggio rilevato, il software invoca una funzione di prototipo 
int ingresso(char * targa) con la targa del veicolo come parametro. La funzione:
Inserisce la targa nella lista dinamica autoInCentro, che è una variabile globale di tipo Lista
Se la targa risulta già nel centro storico, stampa a video un messaggio di errore
Verifica che la targa appartenga a un veicolo registrato nel file pra.txt
Se non è registrato (auto straniera, targa falsa, …) interrompe la ricerca
Controlla se la targa appartiene a uno dei veicoli autorizzati, registrati nel file permessi.txt
Se la targa è registrata e non autorizzata, la inserisce la nel file multe.txt
Si codifichi la funzione ingresso().
I file hanno il formato indicato qui sotto.
	pra.txt			permessi.txt		multe.txt
	AB234XF			AB234XF				BB154TR
	Luigi Verdi		Luigi Verdi			AG677SY
	Panda Turbo		Panda Turbo	...
	BB154TR			BB331FT
	Mario Rossi		Luca Mori
	Cayenne S		...
	BB154TR
	Mario Neri
	Cayenne S
*/


typedef struct Elem { char* targa; struct Elem* next; } Auto;
typedef Auto* Lista;
Lista AutoInCentro;

int cerca(FILE* fp, char* text) {
	char* line = NULL;
	char buffer[256];

	rewind(fp); // 	fseek(fp, 0, SEEK_SET);

	while (fgets(buffer, 255, fp)!=NULL) {
		if (strcmp(text, line) == 0) return 1;
	}
	return -1;
}

int find(Lista cars, char* targa);
void insTesta(Lista* lista, char* targa);

int ingresso(FILE* fpra, FILE* fpermessi, FILE* fmulte, Auto car){

	if (find(AutoInCentro, car.targa) == 1) {
		printf("%s: auto già in centro \n", car.targa);
		return -1;
	}
	insTesta(&AutoInCentro, car.targa);


	int autoRegolare = cerca(fpra, car.targa);
	if (autoRegolare != 1) {
		printf("%s: auto non in pra \n", car.targa);
		return -2;
	}

	int autoConPermesso = cerca(fpermessi, car.targa);
	if (autoConPermesso != 1) {
		fseek(fmulte, 0, SEEK_END);
		fprintf(fmulte, "%s", car.targa);
	}

	return;
}

main() {
	FILE* fpra, *fpermessi, *fmulte;

	if ((fpra = fopen("pra.txt", "r")) == NULL) 
		return -1;

	if ((fpermessi = fopen("permessi.txt", "r")) == NULL) 
		return -2;

	if ((fmulte = fopen("multe.txt", "w")) == NULL)
		return -3;

	// in attesa di una macchina


	return;
}