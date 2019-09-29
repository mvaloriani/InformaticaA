//Scrivere un programma che acquisisce una sequenza di caratteri terminata dal carattere 'invio' 
//e stabilisce se la sequenza è palindroma oppure no (per esempio, "ada" è palindroma perché si legge allo stesso modo sia da destra sia da sinistra)


#include<stdio.h> 
#include<string.h>

#define MAX_DIM 100 
int main() {
	char stringa[MAX_DIM];
	int contatore = 0, i, quanti = 0;
	
	scanf("%s",stringa); 
	contatore = strlen(stringa) - 1;

	for (i = 0; i<contatore / 2; i++)
		if (stringa[i] == stringa[contatore - i])
			quanti++;

	if (quanti == contatore / 2)
		printf("Palindromo");
	else
		printf("Non Palindromo");
	return 0;
}
