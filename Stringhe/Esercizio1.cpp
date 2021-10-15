#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*Scrivere un programma C che legge due
stringhe da tastiera, 
le concatena in un’unica stringa e
stampa la stringa così generata

*/

#include <stdio.h>   
#include <stdlib.h>
#include <string.h>

#define LUNG 200 
int main() {
	char str1[LUNG], str2[LUNG], strTot[2 * LUNG];
	int i, j;

	printf("Inserisci la prima stringa : \n");
	scanf("%s", str1);
	printf("Inserisci la seconda stringa : \n");
	scanf("%s", str2);

	for (i = 0; str1[i] != '\0'; i++)
		strTot[i] = str1[i];

	/* i rappresenta il numero di caratteri copiati da str1 a strTot */
	for (j = 0; str2[j] != '\0'; j++) /* accodo str2 a str1 */
		strTot[i + j] = str2[j];

	strTot[i + j] = '\0';

	////alternativa
	//strTot[0] = '\0';
	////strcat(strTot, str1);
	//strcpy(strTot, str1);
	//strcat(strTot, str2);

	////strcat(str1, str2);

	printf("\n%s\n", strTot);

	system("pause");
	return 0;
}

