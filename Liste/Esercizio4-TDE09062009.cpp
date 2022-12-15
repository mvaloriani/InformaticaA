#include <stdio.h> 
#include <math.h>
#include <stdlib.h>

/*
Si progetti e codifichi una funzione C che riceve in ingresso una lista definita
*/
typedef struct Node {
	int numero;
	struct Node* next;
} Nodo;
typedef Nodo* Lista;

/*che contiene solo valori positivi.
Definiamo picchi della lista quei valori che sono preceduti e seguiti nella lista da valori più piccoli della loro metà. Il primo e l’ultimo elemento della lista non possono essere picchi.
Ad esempio nella lista
	4 9 12 36 16 23 87 34 18 64 33
	36 e 87 sono picchi (perché 36/2=18, 18>12 e 18>16 e 87/2=43,5, 43,5>23 e 43,5>34)
Si progetti e codifichi una funzione C che riceve in ingresso una lista definita come sopra e restituisce il numero di picchi che la lista contiene.



*/