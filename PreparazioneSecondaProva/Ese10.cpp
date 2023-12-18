#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ND { 
	unsigned int matr; 
	char * nome; 
	struct ND * nextMatr,
		* nextNome; } Nodo;
typedef Nodo * ListPtr;
typedef struct DP { ListPtr headMatr, headNome; } Lista; 

/*
La struttura dati dinamica soprastante rappresenta un elenco di studenti
contemporaneamente ordinato rispetto a due criteri indipendenti 
(ordine di nome e di matricola, entrambi crescenti e, per semplicità, entrambi univoci).
Le matricole sono assegnate in modo progressivo ad ogni iscrizione.


(a)	Si codifichi in C la funzione ... aggiungistudente(...) che riceve 
come parametro il nome di uno studente e la lista in cui inserirlo,
restituisce la lista modificata. 

*/
ListPtr trovaCodaMatr( Lista L ) {
	if( L.headMatr == NULL || L.headMatr->nextMatr == NULL )
		return L.headMatr;
	L.headMatr = L.headMatr->nextMatr;
	return trovaCodaMatr(L);
}

ListPtr trovaPrecNome( Lista L,char* name) {
	if( L.headNome == NULL || strcmp(L.headNome->nome,name)>0 )
		return NULL;
	if( strcmp(L.headNome->nome,name)>0 &&
		( L.headNome->nextNome == NULL || strcmp(L.headNome->nextNome->nome)<0 ) )
		return L.headNome;
	L.headNome = L.headNome->nextNome;
	return trovaPrecNome(L, name);
}

ListPtr trovaPrecNome2(ListaPrt L, char* name) {
	if (L == NULL || strcmp(L->nome, name) > 0)
		return NULL;
	if (strcmp(L->nome, name) < 0 &&
		(L->nextNome == NULL && strcmp(L->nextNome->nome) > 0))
		return L;
	return trovaPrecNome(L->next, name);
}

ListPtr trovaPrecNome2(Lista L, char* name) {
	if (L.headNome == NULL || strcmp(L.headNome->nome, name) > 0)
		return NULL;
	return trovaPrecNome2(l.headNome, name);
}


Lista aggiungistudente( Lista L, char * name ) {
	ListPtr lastM = trovaCodaMatr(L);
	ListPtr precN = trovaPrecNome(L, name);

	ListPtr tmp = (ListPtr) malloc(sizeof(Nodo));
	// si vuole copiare la stringa
	tmp->nome = (char*)malloc(strlen(name));
	strcpy(tmp->nome,name);
	tmp->nextMatr = NULL;           // va in coda rispetto alle matricole !

	if( lastM != NULL ) {
		tmp->matr = lastM->matr + 1;  // la matricola è la successiva dell’ultima
		lastM->nextMatr = tmp;
		// va in testa
		if( precN == NULL ) {
			tmp->nextNome = L.headNome;
			L.headNome = tmp;
		}
		// 5nserisco a metà
		else {
			tmp->nextNome = precN->nextNome;
			precN->nextNome = tmp ;
		}
	}
	else {                          // la lista è vuota, inserimento banale
		tmp->matr = 1;
		tmp->nextNome = NULL;         // e’ l’unico nodo anche rispetto al nome
		L.headMatr = L.headNome = tmp;
	}
	return L;
}

/*
(b)	L’elenco degli studenti è conservato su un file ordinato per matricola (crescente),
in cui ogni studente è rappresentato da due righe: la prima contiene la matricola,
la seconda il nome. Si codifichi in C la funzione  ... caricalista(...) 
che apre il file archivio.txt per allocare e restituire la lista degli studenti ivi contenuti. 
*/

Lista caricalista( ) {
	Lista L;
	char buffer[100];
	FILE * fp = fopen("archivio.txt","r");
	fgets(buffer,99,fp);                    // ignoro la matricola (tanto è 1)
	while( fgets(buffer,99,fp) != NULL ) {
		aggiungistudente(L, buffer);
		fgets(buffer,99,fp);                  // ignoro la matricola successiva 
	}
	return L;
}

/*
(c)	Si codifichi ricorsivamente in C la funzione ... miracolo(...)
che verifica (restituendo 1 in caso affermativo, 0 altrimenti) se l’ordinamento
lessicografico della lista ricevuta come parametro coincide con quello per matricola. 
*/

int miracolo( Lista L ) {
  if( L.headMatr != L.headNome )
	return 0;
  if( L.headMatr == L.headNome && L.headMatr == NULL ) 
    return 1;

  L.headMatr = L.headMatr->nextMatr;
  L.headNome = L.headNome->nextNome;
  return miracolo(L);
}

int miracolo2(ListPtr L) {
	if (L->nextMatr != L.nextNome)
		return 0;
	if (L->nextMatr == L->nextNome && L->nextMatr == NULL)
		return 1;
	return miracolo(L->nextMatr);
}

int miracolo(Lista L) {
	if (L.headMatr != L.headNome)
		return 0;
	return miracolo2(L.headNome)
}
/*
(d)	Si consideri la seguente variante astratta della lista precedente,
in cui i nodi hanno solo i due puntatori che inducono gli ordinamenti.
*/
typedef struct ND2 { struct ND2 * nxt1, * nxt2; } Nodo2;
typedef Nodo2 * ListPtr2;
typedef struct DP2 { ListPtr2 head1, head2; } Lista2; 
/*
Si codifichi in modo puramente ricorsivo e senza allocare memoria nello
heap (cioè senza invocare malloc()) la funzione ... ordinamentiopposti(...) 
che verifica se nella lista ricevuta come parametro gli ordinamenti
rappresentati dai due puntatori sono esattamente opposti
(cioè ogni nodo è, in base a uno degli ordinamenti, successivo del suo
successivo in base all’altro ordinamento).
*/


bool ordinamentiopposti(ListPtr2 L){
	if (L==NULL)	{
		return 1;
	}
	if (L->next1 == NULL) {
		return 1;
	}
	if (L->next1->nxt2 == NULL) {
		return 1;
	}

	if (L==(L->nxt1)->nxt2)	{
		return ordinamentiopposti(L->nxt1);
	}
	return 0;
} 