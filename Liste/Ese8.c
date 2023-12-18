#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

/*
Si progetti e codifichi un programma C che apre
il file di testo input.txt e
genera il file di testo output.txt, che contiene,
in ordine inverso ma
inalterate, le sole linee di input.txt che hanno
lunghezza compresa 
tra 10 e 20 caratteri (ignorando le altre linee). 
A tale scopo, il programma alloca una lista dinamica
che contiene le linee da trasferire, 
genera il file scandendo la lista e la dealloca 
prima di terminare.

Si usi la seguente definizione della lista:
typedef struct EL { char linea[21]; struct EL * next; } Nodo;
typedef Nodo * Lista;

Si provi a costruire la lista nel modo più semplice
che permetta poi di generare facilmente l'output
Si può assumere che l'ultima linea di input.txt 
termini con '\n'
e che nessuna linea superi i 255 caratteri

*/


typedef struct EL { char linea[21]; struct EL * next; } Nodo;
typedef Nodo * Lista;

int lista_vuota(Lista lista)
{
	if (lista == NULL) return 1;
	else return 0;
}

int cerca(Lista lista, char* line)
{
	Nodo* punt;
	if (lista_vuota(lista))//definita qui
		return 0;
	else{
		punt = lista;
		
		if (strcmp(punt->linea, line) == 0)
			return 1;
		else
			cerca(punt->next, line);
	}
}

//void insTest(Nodo** lista, char * line)
void insTesta(Lista *lista, char * line) {     // Normale inserimento in
	Lista tmp = *lista;                            // testa con assegnamento
	*lista = (Lista)malloc(sizeof(Nodo));         // del "dato" con strcpy
	strcpy((*lista)->linea, line);
	(*lista)->next = tmp;
}

Lista insTesta2(Lista lista, char * line) {     // Normale inserimento in
	Lista tmp = lista;                            // testa con assegnamento
	lista = (Lista)malloc(sizeof(Nodo));         // del "dato" con strcpy
	strcpy(lista->linea, line);
	lista->next = tmp;
	return lista;
}


void deleteMyList(Lista lista){
	if (lista != NULL){
		deleteMyList(lista->next);
		free(lista);
	}
}

void inCodaRicorsivo(Lista lista, char * line){
	if (lista != NULL){
		inCodaRicorsivo(lista->next, line);
	}
	else
	{
		lista = (Lista)malloc(sizeof(Nodo));         // del "dato" con strcpy
		strcpy((lista)->linea, line);
	}
}

Lista ins_coda(Lista lista, char * line)
{
	Nodo* nuovo;
	Nodo* temp;

	nuovo = (Nodo*)malloc(sizeof(Nodo));
	strcpy(nuovo->linea, line);
	nuovo->next = NULL;

	if (lista_vuota(lista))
	{
		lista = nuovo;
	}
	else
	{
		temp = lista;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = nuovo;
	}
	return lista;
}

void scrivifile(Lista lista, FILE * fp) {
	if (lista != NULL) {
		scrivifile(lista->next, fp);
	}
	else {
		return;
	}
	fputs(lista->linea, fp);
}

int main() {
	FILE * fp;
	char buffer[256];		            // max 255 caratteri + 1 per il '\0'
	Lista lis = NULL, tmp = NULL;

	if ((fp = fopen("input.txt", "r")) == NULL)  // Selezione linee da tenere
		return -1;

	while (fgets(buffer, 256, fp) != NULL){
		if (strlen(buffer) >= 10 && strlen(buffer) <= 20)
			insTesta(&lis, buffer);
		    //lis = insTesta(lis, buffer);
	}
	fclose(fp);

	if ((fp = fopen("output.txt", "w")) == NULL)
		return -2;

	while (lis != NULL) {              // Man mano che trascrivo, dealloco
		fputs(lis->linea, fp);
		tmp = lis;
		lis = lis->next;
		free(tmp);
	}
	fclose(fp);


	return 0;
}


