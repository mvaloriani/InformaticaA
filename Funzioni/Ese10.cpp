/*
Scrivere un programma in linguaggio C che definendo
opportune funzioni, risolva il seguente problema.
Date due stringhe S1 e S2, stabilire se S2 
compare come sottosequenza di S1 e, in caso affermativo,
a partire da quale indice. Creare quindi una nuova stringa S3
costruita come S1 meno la prima occorrenza della stringa S2. 
Non è permesso utilizzare le funzioni di libreria del linguaggio
relative alla manipolazione di stringhe.
Esempio: S1 = “melograno”, S2 = “crano”; 
restituisce 5 (S2 è inclusa in S1 a partire dal 5° carattere) e
S3 = “melo”.
Se fosse S1 = “sperpero”, S2 = “per”;
il risultato è 2 e S3 = “spero”.


*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>





int lung_str(char *s) {
	int i = 0;

	while (s[i] != '\0') {
		i++;
	}

	return i;
}

// restituisce -1 se s2 non è contenuta in s1; altrimenti
// l’indice della cella in cui inizia l’occorrenza di s2 in s1; 
int inclusione_str(char *s1, char *s2) {
	int len1, len2, trovato, i, j, new_i;
	len1 = lung_str(s1);    len2 = lung_str(s2);
	
	if (len1 < len2) return -1;
	
	for (i = 0; i <= len1 - len2; i++) {
		j = 0;
		trovato = 1;
		new_i = i;
		while ((j < len2) && (trovato)) {
			trovato = (s1[new_i] == s2[j]);
			j++;
			new_i++;
		}
		if ((j == len2) && (trovato))
			return i;
	}
	return -1;
}


// s3 conterrà tutti i caratteri di s1 tranne la prima
// occorrenza della stringa s2.
void sottrai_str(char *s1, char *s2, char *s3) {
	int index, len1, len2, i;

	index = inclusione_str(s1, s2);
	if (index == -1)
		return ;

	len1 = lung_str(s1);
	len2 = lung_str(s2);

	for (i = 0; i < index; i++)
		s3[i] = s1[i];

	for (i = index + len2; i < len1; i++)
		s3[i - len2] = s1[i];

	s3[i - len2] = s1[i];  // per aggiungere il char '\0' 
}





int main() {
	char stringa1[MAX_LEN], stringa2[MAX_LEN], stringa3[MAX_LEN];
	int res;
	printf("\n inserisci la prima stringa: ");   scanf("%s", stringa1);
	printf("\n inserisci la seconda stringa: ");   scanf("%s", stringa2);
	res = inclusione_str(stringa1, stringa2);
	if (res == -1)
		printf("\n%s non e' contenuta in %s !", stringa2, stringa1);
	else {
		printf("\n%s in %s inizia in pos %d", stringa2, stringa1, 1 + res);
		sottrai_str(stringa1, stringa2, stringa3);
		printf("\nla stringa differenza e’: s3 = %s", stringa3);
	}
	return 0;
}


