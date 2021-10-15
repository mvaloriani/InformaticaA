/*
Le seguenti dichiarazioni definiscono una struttura 
dati che rappresenta una lista di acronimi
(un acronimo è una sigla in cui ogni lettera è l’iniziale di una parola, come ATM = Azienda Trasporti Milanesi).

Si dichiari (tramite opportuno prototipo) 
la funzione … acronimogiusto(…) che riceve come parametro una struttura 
di tipo Acronym e restituisce 1 se le iniziali delle parole della lista di 
parole corrispondono esattamente alle lettere della sigla, 0 altrimenti. 
Si descriva brevemente (ma in modo preciso) un algoritmo per 
implementarla e la si codifichi in C.

ATTENZIONE:
Gli acronimi possono essere sbagliati per diversi motivi. 
Ecco tre esempi di acronimi sbagliati:
ATM = Azienda Trasporti Romani,
ATM = Azienda Tessile,
ATM = Associazione Turistica Milano Marittima.
Se la sigla è una stringa vuota o la lista di parole è 
una lista vuota, l’acronimo è (convenzionalmente) giusto se e
solo se anche l’altro componente dell’acronimo è vuoto.

Si codifichi in C (preferibilmente in modo ricorsivo) una funzione 
che effettui la deallocazione di una lista di acronimi, secondo il prototipo:
void freeAcroList( AcroList )
Si badi a non deallocare solamente gli elementi di
tipo AcroNode che compongono la lista di acronimi, 
ma anche le liste di parole contenute in ciascun acronimo. 
Eventuali funzioni ausiliarie devono essere anch’esse codificate.

*/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>


typedef char Word[100];

typedef struct WNode {
	Word parola;
	struct WNode * next;
} WordNode;
typedef WordNode * WordList;

typedef struct Acro {
	Word sigla;
	WordList listaparole;
} Acronym;

typedef struct ANode {
	Acronym acronimo;
	struct ANode * next;
} AcroNode;

typedef AcroNode * AcroList;

int acronimogiusto(Acronym a) {
	int i = 0, lung = strlen(a.sigla);

	WordList tmp = a.listaparole;

	while (i < lung && tmp != NULL) {
		if (a.sigla[i] != tmp->parola[0])
			return 0;
		i = i + 1;
		tmp = tmp->next;
	}
	if (i == lung && tmp == NULL)
		return 1;
	else
		return 0;
}


void freeWordList(WordList list) {
	if (list != NULL) {
		WordList tmp = list->next;
		free(list);    
		freeWordList(tmp);
	}
	return;
}

void freeAcroList(AcroList list) {
	if (list != NULL) {
		AcroList tmp = list->next;
		freeWordList((list->acronimo).listaparole);
		//WordList tmp2 = (list->acronimo).listaparole;
		//while (tmp2 != NULL) {
		//	WordList tmp3 = tmp2;
		//	tmp2 = tmp2->next;
		//	free(tmp3);		
		//}
		free(list);    
		freeAcroList(tmp);
	}
	return;
}
