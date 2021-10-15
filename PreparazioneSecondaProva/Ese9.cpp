#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Intv { int da, a; 
struct Intv * next; } Intervallo;
typedef Intervallo * Lista;



void inverti(Lista prec, Lista cur){}
void inverti(Intervallo* prec, Intervallo*cur) {}

void invertiIn Lista(Lista prec) {
	Lista temp = prec->next;
	prec->next = prec->next->next;
	temp->next = prec->next->next;
	prec->next->next = temp;
}
Lista invertiInTesta Lista(Lista testa) {
	Lista temp = testa->next;
	testa->next = temp->next;
	temp->next = testa;
	return temp;
}
void inverti(Intervallo* prec) {}



/*
La struttura soprastante definisce una lista di intervalli
definiti sui numeri interi. Si ritenga assicurato per costruzione
che da < a per ogni intervallo.

(a)	Si implementi in C la funzione sovrapposti() che riceve in input due intervalli e restituisce 1 
se due intervalli hanno almeno un punto in comune, 0 altrimenti 

i1             6---9
i2       5---8

*/ 



//! ( i1.a < i2.da || i2.a < i1.da )    =    ( i1.a >= i2.da && i2.a >= i1.da )

int sovrapposti( Intervallo i1, Intervallo i2 ) {
	//return !(i1.a < i2.da || i2.a < i1.da);
	return  i1.da >= i2.a && i2.a >= i1.da;
}

/*b)	Si implementi in C la funzione fondi() che riceve in input due intervalli
(che assume essere sovrapposti, senza controllare) e restituisce un nuovo intervallo
definito dall’unione dei due in input [2 punti]
*/

//I due intervalli in input sono sovrapposti (per ipotesi),
//costruiamo l’intervalllo che inizia dal minore
//dei valori di “da” e termina nel maggiore dei valori di “a”.

Intervallo fondi( Intervallo i1, Intervallo i2 ) {
	if ( i1.da > i2.da )
		i1.da = i2.da;
	if ( i1.a < i2.a )
		i1.a = i2.a;
	i1.next = NULL; // riutilizziamo uno dei parametri formali. Il puntatore next è azzerato per cancellare l’eventuale riferimento.
	return  i1;
}

/*
(c)	Si implementi in C la funzione coalesce() che riceve in input una
lista di intervalli e restituisce una seconda lista (interamente da allocare)
che contiene tutti e soli gli intervalli “massimi” che coprono lo stesso spazio
coperto dagli intervalli della lista in input. 
*/

Lista buildNode(int DA, int A){

	Lista lista = (Lista)malloc(sizeof(Intervallo));
	lista->a=DA;	
	lista->a=A;	

	return lista;
}

int inserisci(Lista lista, Intervallo inter){
	Lista temp=lista;
	Lista aux=NULL;
	int n=0;
	while (temp->next!=NULL)
	{
		// trovato un intervallo sovrapposto
		if(sovrapposti(*temp,inter)){
			//salvo il successivo o andrebbe perso
			aux=temp->next;
			*temp = fondi(*temp,inter);
			temp->next=aux;
			n=n+1;
		}
		//Avanzo
		temp= temp->next;
	}
	// non ho trovato elementi con cui sovrapporlo lo aggiungo
	if(n==0)
		temp->next=buildNode(inter.da, inter.a);
	return n;

}

Lista coalesce(Lista lista){
	if(lista==NULL)
		return lista;
	// prendo il primo e inizialiazzo la nuova lista
	Lista listaMassimi;
	int count;
	do
	{

		listaMassimi = buildNode(lista->da, lista->a);
		lista = lista->next;
		count = 0;
		while (lista->next!=NULL){
			count=count+inserisci(listaMassimi, *lista);
			lista=lista->next;		
		}
		lista=listaMassimi;

	} while (count!=0);

	return listaMassimi;

}