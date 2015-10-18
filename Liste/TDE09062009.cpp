
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
}


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
}
