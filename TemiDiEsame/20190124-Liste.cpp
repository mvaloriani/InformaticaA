/*Esercizio  5  ( 12 punti )
Si definisca un tipo di dato atto a contenere una lista di studenti
con i campi numero di matricola, nome, cognome e voto all’esame di “Informatica A”.

Si implementi quindi la funzione eliminaStudente
che rimuove da una lista definita
come sopra tutti gli studenti che hanno 
conseguito un punteggio all’esame minore di 18.

Si implementi quindi la funzione listaDiStudendiPerVoto che riceve una
lista definita come sopra e restituisce una lista di liste di studenti
composta da sottoliste costruite dividendo gli studenti per voto ottenuto.
Avremo quindi la sottolista degli studenti che hanno preso 18,
quella degli studenti che hanno preso 19,
e così via fino alla lista degli studenti
che hanno preso 30 (per semplicità non si consideri il “30 e Lode” 
e si immagini
non esistano voti mai assegnati).
*/


#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

#define N 20

typedef char Stringa[N];

typedef struct SNode {
	Stringa Nome;
	Stringa Cognome;
	int Matricola;
	int Voto = 0;
	struct SNode* next;
} Studente;
typedef Studente* Lista;


Lista eliminaStudente(Lista l) {
	Lista temp = l;
	Studente* prev = NULL;
	Studente* next = NULL;

	while (temp != NULL) {
		if (temp->Voto >= 18) {
			prev = temp;
			temp = temp->next;			
		}
		else {
			if (prev == NULL)//primo elemento			
				l = next = temp->next;
			else
				prev->next = next = temp->next;
			free(temp);
			temp = next;
		}
	}
	return l;
}

void eliminaStudenteRif(Lista* l) {
	Lista temp = *l;
	Studente* prev = NULL;
	Studente* next = NULL;

	while (temp != NULL) {
		if (temp->Voto >= 18) {
			prev = temp;
			temp = temp->next;
		}
		else {
			if (prev == NULL)//primo elemento
				*l = next = temp->next;
			else
				prev->next = next = temp->next;
			free(temp);
			temp = next;
		}
	}
}

void eliminaStudenteRifRic(Lista* l) {
	Lista temp = *l;

	if (temp == NULL) return;

	if (temp->Voto >= 18)
		eliminaStudenteRifRic(&temp->next);
	else {
		*l = temp->next;
		free(temp);
		eliminaStudenteRifRic(l);
	}
}

typedef struct SVNode {
	int Voto;
	Lista studenti;
	//Studente* last;
	struct SVNode* next;
} StudentiVoto;

typedef StudentiVoto* Graduatoria;

Graduatoria trova(Graduatoria g, int voto) {
	while (g != NULL)
	{
		if (g->Voto == voto)
			return g;
	}
	return NULL;
}

StudentiVoto* buildSVNode(Studente* s) {
	StudentiVoto* lista;
	lista = (StudentiVoto*)malloc(sizeof(StudentiVoto));

	if (s == NULL)
		return lista;

	lista->Voto = s->Voto;

	//lista->studenti = s; ERRORE avrei un nex sbagliato
	lista->studenti = buildSNode(s);

	lista->next = NULL;
	return lista;
}

Studente* buildSNode(Studente* s) {
	Studente* ret = (Studente*)malloc(sizeof(Studente));
	copy(s, ret);
	return ret;
}


void InserisciInTestaRif(Studente* n, Lista* PuntatoreATesta) { //(Nodo* n, Nodo** testa)
	n->next = *PuntatoreATesta;
	*PuntatoreATesta = n;
	return;
}

 void InserisciInCodaRic(StudentiVoto* n, Graduatoria* testa) { //(Lista n, nodo* testa)
	
	 if (testa == NULL)
		 *testa = n;

	if (testa->next != NULL)
		InserisciInCodaRic(n, testa->next);
	else
		testa->next = n;
}


void copy(Studente* s1, Studente* s2) {
	s2->Voto = s1->Voto;
	s2->Matricola = s1->Matricola;
	strcpy(s2->Cognome, s1->Cognome);
	strcpy(s2->Nome, s1->Nome);
}

Graduatoria listaDiStudendiPerVoto(Lista l) {
	Studente* sTemp = l;
	StudentiVoto* svTemp = NULL;
	Graduatoria g = NULL;

	eliminaStudenteRif(&sTemp);

	if (sTemp == NULL) return NULL;

	while (sTemp != NULL)
	{
		svTemp = trova(g, sTemp->Voto);

		if (svTemp != NULL) {
			InserisciInTestaRif(sTemp, &svTemp->studenti);
		}
		else{
			InserisciInCodaRic(buildSVNode(sTemp),g);
		}
	}
	return g;
}


Graduatoria listaDiStudendiPerVoto(Lista l) {
	Studente* sTemp = l;
	StudentiVoto* svTemp = NULL;
	Graduatoria g = NULL;

	eliminaStudenteRif(&sTemp);

	if (sTemp == NULL) return NULL;

	for (int i = 18; i < 31; i++)
	{
		svTemp = buildSVNode(NULL);
		svTemp->Voto = i;
	
		InserisciInCodaRic(svTemp, g);
	}

	do
	{
		svTemp = trova(g, sTemp->Voto);
		InserisciInTestaRif(sTemp, svTemp->studenti);
	} while (sTemp!NULL);

	return g;
}