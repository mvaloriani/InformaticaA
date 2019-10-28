#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Uno dei modi più semplici (e ormai meno efficaci)
di cifrare un messaggio consiste nell'applicare una
trasformazione "rotatoria" alle lettere che lo compongono,
sostituendo ogni lettera con la lettera che si trova,
nell'ordinamento alfabetico, k posizioni più avanti.
Le ultime k-1 lettere dell'alfabeto sono trattate "rientrando"
dall'inizio dell'alfabeto. Esempio:
offset? 2
mi piace questo corso
ok rkceg swguvq eqtuq
Per k=0 il messaggio resta inalterato, per k=1 ogni lettera
è sostituita dalla successiva (e la z dalla a), per k=-1
dalla precedente (e la a dalla z).
Si scriva un programma C che legga un intero k e una sequenza
di caratteri e restituisca su stdout la sequenza cifrata.
(per brevità, si considerino solo i caratteri minuscoli).

Si noti che, essendo 26 le lettere dell'alfabeto inglese, per k=13
l'algoritmo di cifratura è identico a quello di decifratura, e che
per k = 26 il messaggio resta inalterato come per k=0. Si verifichi
la "robustezza" della soluzione proposta utilizzando valori di k
pari a 26 o superiori (per k=27 il comportamento dev'essere 
uguale a quello con k = 1)..

*/

#include <stdio.h>   // inclusione libreria standard per I/O
#include <stdlib.h>  // inclusione libreria standard per funzioni di sistema
#include <string.h>  // inclusione libreria standard per gestione stringhe

#define LUNG 100

int main() {
	char str1[LUNG], str2[LUNG];
	int key = 0;


	printf("inserire un valore di chiave K: ");
	scanf("%d", &key);

	key = key % 26;

	printf("inserire una stringa: ");
	scanf("%s", str1);

	for (int i = 0; i < strlen(str1); i++)
	{
		if (str1[i] + key <= 'z')
		{
			str2[i] = str1[i] + key;
		}
		else {
			str2[i] = str1[i] + key - 26;
		}
	}
	str2[strlen(str1)] = '\0';

	printf("stringa cifrata: %s", str2 );

	printf("\n");
	system("pause");
	return 0;
}

