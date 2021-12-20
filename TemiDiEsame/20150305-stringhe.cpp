/*
Esercizio  4  ( 6 punti )
Il DNA è composto da quattro basi azotate: adenina (A), guanina (G), citosina (C) e timina (T).
Il DNA è una doppia catena polinucleotidica (A,T,C,G) in cui ogni tipo di base
presente su un filamento forma un legame con la base posta sul filamento opposto.
Tale evento è noto come appaiamento complementare: A può legare solo T e G può legare solo C.
Date quindi due catene di basi, esse possono essere le due catene dello stesso DNA se
in corrispondenza di ogni base della prima nella seconda c’è la base complementare
Esempi:
AGGTCATTCG
TCCAGTAAGC
sono compatibili
Mentre
AGGTCATTCG
TCCCGGAAGC
non lo sono a cause delle non corrispondenze evidenziate in grassetto.
Si codifichi in C una funzione  int compatibili(char * S1, char * S2) che riceve le
due catene di un DNA e restituisce 1 se sono compatibili, 0 altrimenti.

*/

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

int valido(char* S1, char* S2) {
	if ((*S1 == 'A' && *S2 == 'T') || (*S2 == 'T' && *S2 == 'A') ||
		(*S1 == 'G' && *S2 == 'C') || (*S2 == 'C' && *S2 == 'T'))
		return 1;
	return 0;
}


int compatibili(char* S1, char* S2) {

	int s1Len, s2Len;
	s1Len = strlen(S1);
	s2Len = strlen(S2);

	if (s1Len != s2Len) return 0;

	for (int i = 0; i < s1Len; i++)
	{
		if (valido(&S1[i], &S2[i]) == 0)
			return 0;
	}
	return 1;

}

