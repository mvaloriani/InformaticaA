/*
Scrivere un programma C che legge due stringhe da tastiera, 
le concatena in un’unica stringa e stampa la stringa così generata
*/

#include <stdio.h>
#define LUNG 200 
int main () { 
	char str1[LUNG],str2[LUNG],strTot[2*LUNG];
	int i,j; 
	printf("Inserisci la prima stringa:\n"); 
	scanf("%s",str1);
	printf("Inserisci la seconda stringa:\n"); 
	scanf("%s",str2);
	//copio la prima stringa
	for (i=0;str1[i]!='\0';i++)
		strTot[i]=str1[i];
	/* i rappresenta il numero di caratteri copiati da str1 a strTot */
	for (j=0;str2[j]!='\0';j++) /* accodo str2 a str1 */ 
		strTot[i+j]=str2[j]; 
	strTot[i+j]='\0'; 
	printf("\n%s",strTot); 
	return 0; 
} 
