#include <stdio.h> 
#include <math.h>
#include <stdlib.h>

///*
//a)	Quanto vale mistero(7) e mistero(8)?
//b)	Cosa calcola in generale la funzione mistero(x)?
//
//*/

//
//int mistero(int x){
//
//	if(x>=1)
//		return (x%2)+10*mistero(floor(x/2.0));
//	else
//		return 0;
//}
//
//
//int main(){
//	int result;
//	result = mistero(7);
//	for(int i=0; i<=8; i++){
//		result = mistero(i);
//		printf("Risulatato %d\n", result);
//	}
//	system("pause");
//	return 0;
//}

#define MATR "623372"       /* Ad esempio, "623372" */

void f(char * c1, char * c2, int * n)
{
	*n = *n + 1;                 /* Innanzitutto incrementa n (dereferenziato)      */

	if (c1 >= c2)              /* Se ... (attenzione a cosa si confronta)         */
		return;                 //<--- /* termina e restituisce il controllo al chiamante */
	else                         /* Altrimenti effettua una chiamata ricorsiva in   */
		f(c1 + 1, c2 - 1, n);      /* cui ... i puntatori ... (attenzione a + e -)    */

	if (*c1 >= *c2) {          /* Se ... (attenzione a cosa si confronta), allora */
		c1 = c2;                 /* esegue due assegnamenti (ancora attenzione a *) */
		*n = *n + 10;
	}
	printf("%c", *c1);           /* Quindi stampa a video il carattere ...          */

	return;                      /* Termina e restituisce il controllo al chiamante */
}

int main() {
	char mat[7] = MATR;          /* 6 caratteri per la matricola e 1 per il '\0'    */
	int cont = 0;
	printf("%s - ", mat);         /* stampa per prima la matricola e effettua una    */
	f(mat, mat + 5, &cont);       /* chiamata ricorsiva passando primo e ultimo char */
	printf(" - %d", cont);
	return 0;
}
