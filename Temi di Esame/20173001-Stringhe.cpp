/*Scrivere una funzione che riceve due stringhe : parola e elimina.
La funzione cerca in parola tutti i caratteri che compongono la
stringa elimina, e li rimuove solamente se li trova tutti e
nell’ordine in cui compaiono in elimina, anche se non consecutivi.
L’operazione viene ripetuta finché in parola è contenuta un’intera
istanza della stringa elimina.
La funzione, oltre a modificare l’array parola,
restituisce il numero di volte che ha eliminato i caratteri
dell’intera stringa elimina da parola.

Nell’eliminare caratteri non
devono essere lasciati buchi, ma parola dev’essere ricompattata.

Esempio
parola: amaarrreeeemmmmarrreeaaaarrrmae
elimina: mare
La funzione trova tutte le lettere di “mare” in
“aMAaRrrEeeemmmmarrreeaaaarrrmae” che diventa
“aarreeemmmmarrreeaaaarrrmae”
La funzione trova tutte le lettere di “mare” in
“aarreeeMmmmARrrEeaaaarrrmae” che diventa
“aarreeemmmrreaaaarrrmae”
La funzione trova tutte le lettere di “mare” in
“aarreeeMmrreAaaaRrrmaE” che diventa
“aarreeemmrreaaarrma”

Poi non trova più tutte le lettere e restituisce 3*/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int pulizia(char* parola, char* elimina) {

	int eliminaLen, parolaLen;
	int count = 0, temp=0;
	int* indexes;

	parolaLen = strlen(parola);
	eliminaLen = strlen(elimina);	

	if (eliminaLen == 0 || eliminaLen > parolaLen) return 0;

	indexes = (int*)malloc(sizeof(int) * eliminaLen);

	do
	{
		temp = findIndexs(parola, elimina, indexes);

		if (temp == eliminaLen) {
			count++;
			for (int i = 0; i < eliminaLen; i++){
				RemoveChar(parola, indexes[i] - i);
			}
		}
	}while(temp==eliminaLen)

	return count;

}

int findIndexs(char* parola, char* elimina, int* indexes) {

	int count = 0;
	int i = 0, j = 0;

	while (parola[i] != '\0' || elimina[j] != '\0')
	{
		if (parola[i] == parola[j]) {
			count++;
			indexes[j] = i;
			j++
		}
		i++;
	}

	return count;

}


void RemoveChar(char* s, int index)
{
	int writer = 0, reader = 0;
	while (s[reader] != '\0')
	{
		if (reader != index)
		{
			s[writer] = s[reader];
			writer++;
		}
		reader++;
	}
	s[writer] = '\0';
}

void RemoveChars2(char* s, int index) {
	strcpy(&s[index], &s[index + 1])
}
