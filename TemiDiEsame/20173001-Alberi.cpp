//Si consideri la seguente definizione di albero binario :

typedef struct t {
    char parola[1000];
    struct t* left, * right;
} Nodo;
typedef Nodo* Tree;

/*
Due parole si dicono simili se hanno al più due caratteri 
diversi(cioè se hanno gli stessi caratteri nello stesso ordine, 
eccetto due di essi che possono essere diversi o mancare nella 
seconda o essere in più nella seconda parola).

Una catena di parole si dice compatibile col telefono
senza fili(cctsf) se ogni parola è simile alle adiacenti.
La funzione int simili(char* s1, char* s2); 
restituisce 1 se s1 e s2 sono simili, 0 altrimenti.

Usando la funzione simili(…) (senza codificarla),
si codifichi in C una funzione f che riceve come parametro
un albero di parole(secondo la definizione soprastante) e 
restituisce 1 se tutti i cammini dalla radice alle foglie 
rappresentano catene cctsf, 0 altrimenti.
*/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int simili(char* s1, char* s2);

int f(Tree t) {
    int rl = 0, rr = 0;

    if (t == NULL) return 1;

    if (t->left == NULL && t->right == NULL) return 1;

    if (t->left != NULL && simili(t->parola, t->left->parola) == 0) return 0;

    if (t->right != NULL && simili(t->parola, t->right->parola) == 0) return 0;

    rl = f(t->left);
    rr = f(t->right);

    //return rr + rl == 2;
    //if (rl + rr == 2)
    //    return 1;
    //else
    //    return 0;

    
    return f(t->left) + f(t->right) == 2 ? 1 : 0;
    return rl + rr == 2 ? 1 : 0;

  
}

//Si consideri la seguente definizione di albero binario :

typedef struct t {
    char parola[1000];
    struct t* left, * right;
} Nodo;
typedef Nodo* Tree;

/*
Due parole si dicono simili se hanno al più due caratteri
diversi(cioè se hanno gli stessi caratteri nello stesso ordine,
eccetto due di essi che possono essere diversi o mancare nella
seconda o essere in più nella seconda parola).

Una catena di parole si dice compatibile col telefono
senza fili(cctsf) se ogni parola è simile alle adiacenti.
La funzione int simili(char* s1, char* s2);
restituisce 1 se s1 e s2 sono simili, 0 altrimenti.

Usando la funzione simili(…) (senza codificarla),
si codifichi in C una funzione f che riceve come parametro
un albero di parole(secondo la definizione soprastante) e
restituisce 1 se tutti i cammini dalla radice alle foglie
rappresentano catene cctsf, 0 altrimenti.
*/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int simili(char* s1, char* s2);

int f(Tree t) {
    int rl = 0, rr = 0;

    if (t == NULL) return 1;

    if (t->left == NULL && t->right == NULL) return 1;

    if (t->left != NULL && simili(t->parola, t->left->parola) == 0) return 0;

    if (t->right != NULL && simili(t->parola, t->right->parola) == 0) return 0;

    rl = f(t->left);
    rr = f(t->right);

    //return rr + rl == 2;
    //if (rl + rr == 2)
    //    return 1;
    //else
    //    return 0;


    return f(t->left) + f(t->right) == 2 ? 1 : 0;
    return rl + rr == 2 ? 1 : 0;


}