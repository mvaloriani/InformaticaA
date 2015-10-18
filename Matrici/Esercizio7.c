/*
Scrivere un programma che acquisisce una sequenza di caratteri terminata dal carattere 'invio'
e stabilisce se la sequenza è palindroma oppure no (per esempio, "ada" è palindroma perché si 
legge allo stesso modo sia da destra sia da sinistra)

*/

#include<stdio.h> 
#include<string.h>
#include<stdlib.h>

#define MAX_DIM 100 
int main() { 
	char stringa[MAX_DIM]; 
	int contatore=0, i, quanti=0 ; 

	scanf("%s",stringa); 
	contatore=strlen(stringa);

	//confronto prima e ultima lettera
	for(i=0;i<contatore/2;i++)
		if(stringa[i]==stringa[contatore-1-i])
			quanti++;
	if(quanti==contatore/2) 
		printf("Palindromo\n");
	else
		printf("Non Palindromo\n");

	system("pause");
	return 0; 
} 
