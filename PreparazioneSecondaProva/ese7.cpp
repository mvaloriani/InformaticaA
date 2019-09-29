#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*Il seguente programma C legge un intero n da terminale e stampa due volte
a video i numeri della serie  1^1  2^2 ... i^i ... n^n,
tramite le funzioni f1() e f2(), che hanno lo stesso effetto.

int main () {
int n;
printf ("Inserisci un intero : ");
scanf ("%d", &n);
f1(n);
f2(n);
}
*/

/*(a) 	Supponendo di disporre della funzione int potenza(int base, int esponente);
che realizza l’elevamento a potenza intera di un numero intero, si codifichi in
C la funzione iterativa f1()  
*/

void f1 (int n) {
	int i;
	for (i=1; i<=n; i++)
		printf ("%d", potenza(i, i));
	return;
}

/*(b) 	Si codifichi in modo ricorsivo la funzione potenza(),
considerando solo il caso in cui sia la base sia l’esponente sono strettamente positivi 

Il caso base è chiaramente quello per cui l’esponente vale 1: 
il risultato è allora pari alla base. 
Il passo induttivo si formalizza notando che be = b x be-1 (la ricorsione, cioè, si fa solo sull’esponente).
*/
	int potenza (int b, int e) {
		if ( e == 1 )
			return b;
		else
			return ( b * potenza(b, e-1) );
}

/*(c) 	Sempre sfruttando la funzione potenza(),
si codifichi in C la funzione ricorsiva f2(), 
basandola sulla definizione seguente (da completare).
Attenzione a stampare i valori nell’ordine giusto.
	caso base: se n vale 1, stampa a video ...        
	passo induttivo: se n è maggiore di 1 ...

Evidentemente si eseguono le chiamate ricorsive diminuendo 
il parametro n fino a portarlo a 1. L’unica difficoltà consiste
nel generare l’output nell’ordine corretto: è tipico, infatti, 
non badare a mettere l’istruzione di stampa a video DOPO la chiamata
ricorsiva (l’effetto è di visualizzare la sequenza invertita).
*/
	void f2 (int n) {
		if ( n == 1 )
			printf ("1");
		else {
			f2( n-1 );
			printf ("%d", potenza(n, n));
		}
		return;
}
//Eccone anche una versione alternativa, equivalente, un po’ più compatta:
void f2 (int n) {
	if ( n > 1 )
		f2( n-1 );
	printf ("%d", potenza(n, n));
	return;
}
