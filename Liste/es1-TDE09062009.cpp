
#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

typedef struct EL { char linea[21]; struct EL * next; } Nodo;
typedef Nodo * Lista;

void fun(Lista lis1, Lista lis2) {
	if (lis1 == NULL)
		return;


	else if (lis1->next != NULL)
		fun(lis1->next, lis2);
	else
		lis1->next = lis2;
}
void foo(Lista lis1, Lista lis2) {
	fun(fun(lis1, lis2), fun(lis1, lis2));

	//fun2(lis1, lis2);
	//fun2(lis1, lis2);
	//fun2(,);
}

/* Errore di compilazione perchè la funzione ritorna void
*/

Lista fun2(Lista lis1, Lista lis2) {
	if (lis1 == NULL)
		return lis1;
	else if (lis1->next != NULL)
		lis1 = fun2(lis1->next, lis2);
	else
		lis1->next = lis2;
	return lis1;
}


void foo2(Lista lis1, Lista lis2) {
	fun2(fun2(lis1, lis2), fun2(lis1, lis2));

	//Lista l1 = fun2(lis1, lis2);
	//Lista l2 = fun2(lis1, lis2);
	//fun2(l1,l2);

}


/*La prima chiamata annidata a fun concatena lis2 in coda a lis1,
la seconda concatena lis2 in coda alla nuova lis1,
ma visto che i nodi di lis2 sono sempre gli stessi abbiamo una
lista che contiene un ciclo(l’ultimo elemento punta a quello che è il primo elemento di lis2)
La chiamata a fun che contiene le altre non termina

A-B-C-D-1-2-3-4
        |______|

*/
