#include <string.h>
#include <stdio.h>
#include <stdlib.h>


/*
Si consideri una lista concatenata semplice di parole. 
La lista rappresenta un indice di parole, elencate in ordine alfabetico e
accompagnate da un numero, che rappresenta la pagina in cui la parola compare
per la prima volta in un libro. La struttura della lista è:

*/
typedef struct Guscio { char * parola; int pagina; struct Guscio * next;  } Nodo;
typedef Nodo* Indice;

/*
(a)	Si implementi la funzione di prototipo void 
scambiaPrimeParole( Indice * idx ); che “danneggia” l’indice
ordinato scambiando tra loro i primi due nodi (se presenti). 
*/

void scambiaPrimeParole( Indice* idx ) {  
	Indice temp;  
	// ci sono meno di due nodi?
	if ( *idx == NULL || (*idx)->next == NULL )  
		return; 

	// prendo il secondo puntatore
	temp = (*idx)->next;
	// associo il terzo al primo
	(*idx)->next = temp->next;   
	//associo  al secondo il primo
	temp->next = *idx;      
	// cambio il puntatore di testa
	*idx = temp;                   
	return;
	// avendo passato il puntatore al puntatore di testa non è necessario ritornare nulla 
}


//(b)	 Si dica brevemente (ma in modo preciso) qual è l’effetto della funzione seguente

void funzione( Indice idx ) {
	Indice idy = idx;
	// eseguo solo se + di 2 elementi
	if ( idy == NULL || idy->next == NULL )
		return;
	//finche non arrivo al penultimo
	while ( idx->next->next != NULL ) {
		//avanzo la posizione iniziale
		idx = idx->next;
	}
	// rendo circolare, l'ultimo rimane senza puntatori
	idx->next = idy;
	return; 
}


/*c)	Si codifichi la funzione ricorsiva di prototipo
int trovaPagina( Indice idx, char * lemma ); 
che restituisce la pagina relativa alla parola lemma
se questa è nell’indice, oppure –1 se non è nell’indice,
badando ad attraversare in entrambi i casi solo la porzione necessaria della lista.
*/

int trovaPagina( Indice idx, char * lemma ) {
	// sono in fondo alla lista o ho superato la parola che cerco ritorno -1
	if ( idx == NULL || strcmp(idx->parola, lemma) > 0 )  
		return -1;
	// se ho trovato la parola ritorno l'indice
	if ( strcmp(idx->parola, lemma) == 0 )  
		return idx->pagina;  
	else  
		// proseguo sulla parte restante della lista.
		return trovaPagina(idx->next, lemma);   
}


/* 2)	Si codifichi la funzione cleanup di prototipo 
void   cleanup ( Indice * idx );   oppure, a scelta, di prototipo
Indice cleanup ( Indice idx );
che elimina dall’indice idx (deallocandoli) tutti i nodi che contengono informazioni
non valide (puntatori a NULL o stringhe di lunghezza zero come parole, valori negativi
o nulli come numeri di pagina), lasciando gli altri nodi correttamente concatenati.
Nel caso del primo prototipo la testa della lista è passata per indirizzo,
nel caso del secondo la funzione restituisce un puntatore alla testa della lista modificata.
*/

Indice cleanup( Indice idx ) {	   
	Indice temp,prec,testa=NULL; 
	while (idx != NULL) {
		// violo una condizione
		if (idx->parola==NULL||strlen(idx->parola)==0||idx->pagina<=0){
			//salvo l'indice e poi avanzo
			temp=idx;
			idx=idx->next;
			//libero la memoria del nodo corrotto
			free(temp);
		}
		// nodo corretto, non lo elimino
		else{
			// primo elemento corretto trovato lo salvo come testa
			if(testa==NULL){			
				testa=idx;
				prec=testa;
			}
			else{
				// aggiorno la lista degli indici corretti
				prec->next=idx;
				prec=prec->next;
			}
			//avanzo la lista da controlare
			idx=idx->next;
		}
	}
	return testa;
} // questa versine è molto efficiente se i nodi da ripulire è molto alta


//variante ricorsiva
Indice cleanup( Indice idx ) {
	Indice aux;
	if (idx == NULL) return idx;

	if (idx->parola==NULL||strlen(idx->parola)==0||idx->pagina<=0){
		aux = idx;
		idx = cleanup(idx->next);
		free(aux);
	} else
		idx->next = cleanup(idx->next);
	return idx;
}


