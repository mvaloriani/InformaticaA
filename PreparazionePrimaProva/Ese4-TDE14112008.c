/*
Definiamo sequenza monotona crescente in un vettore una sequenza di elementi 
contigui in cui ogni elemento in posizione i+1 è più grande di quello in posizione i.
4 5 7 è una sequenza monotona crescente di lunghezza 3
6 8 è una sequenza monotona crescente di lunghezza 2
Definiamo sequenza monotona decrescente in un vettore una sequenza di elementi
contigui in cui ogni elemento in posizione i+1 è più piccolo di quello in posizione i.
7 3 1 è una sequenza monotona decrescente di lunghezza 3
4 2 è una sequenza monotona decrescente di lunghezza 2
Un array di interi si dice uniformemente oscillante se tutte le sequenze monotone
(crescenti o decrescenti) massime (cioè non contenute in altre sequenze monotone)
che contiene hanno la stessa lunghezza. Codificare una funzione che riceve in ingresso
un vettore V e la sua dimensione N e restituisce 1 se il vettore è uniformemente
oscillante, 0 altrimenti. 
Esempi:
4 5 7 3 1 5 9 4 3 è uniformemente oscillante (tutte le sequenze crescenti o decrescenti sono lunghe 3)
0 1 0 -1 0 1 0 -1 non è uniformemente oscillante (la prima sequenza 0 1 è più corta delle altre)
*/

#include <stdio.h>

int uniformementeOscillante(int v[], int N){
	int i,asc,cont=1,oldCont,prima=1;
	//direzione iniziale
	if(v[0]<v[1])
		asc=1;
	else
		asc=0;

	//scorro il vettore
	for(i=1;i<N-1;i++) {
		// funzione monotona
		if( (asc==1 && v[i]<v[i+1]) || (asc==0 && v[i]>v[i+1])){
			//incremento la lunghezza
			cont++;
		}
		else {
			// prima variazione direzione 
			if (prima==1) {
				prima=0;  
				oldCont=cont;
			} 
			
			else {
				// controllo se i tratti monotoni hanno la stessa lunghezza
				if(oldCont!=cont)
					return 0;
			}  
			//inverto la direzione
			asc=!asc;
			//risetto la lunghezza
			cont=1;   

		}      
	}       
	return 1;                      
}
