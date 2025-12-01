/*
Scrivere un programma C che legge un vettore di 
lunghezza arbitraria e
stampa 1 se il vettore contiene solo 
valori diversi, 0 altrimenti. 
*/

#include<stdio.h>

int const DIM = 10;

int main() {
  int v[DIM], i, j, si=1;
 /* ometto codice lettura vettore */
  for ( i = 0; i < DIM-1; i++ )
    for ( j = i+1; j < DIM; j++ )
      if ( v[i] == v[j] )
        si=0;
  printf("%d\n",si);  
  return 0;
}


int main2() {
    int v[DIM], i, j, si = 1;
    /* ometto codice lettura vettore */
    for (i = 0; i < DIM - 1 && si == 1; i++)
        for (j = i + 1; j < DIM && si == 1; j++)
            if (v[i] == v[j])
                si = 0;
    printf("%d\n", si);
    return 0;
}

int main3() {
    int v[DIM], i, j, si = 1;
    /* ometto codice lettura vettore */
    for (i = 0; i < DIM - 1 && si == 1; i++)
        for (j = i + 1; j < DIM && si == 1; j++)
            if (v[i] == v[j]) {
                printf("si");
                return 0;
            }
                
    printf("no");
    return 0;
}


int main4() {
    int v[DIM], i, j, si = 1;
    /* ometto codice lettura vettore */
    for (i = 0; i < DIM - 1; i++)
        for (j = 0; j < DIM; j++)
            if (v[i] == v[j] && i!=j )
                si = 0;
    printf("%d\n", si);
    return 0;
}
