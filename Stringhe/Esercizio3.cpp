#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Scrivere un programma che chieda di inserire
una sequenza di caratteri, fino allo spazio,
riconosca se i caratteri inseriti sono cifre
pari o dispari o se sono altro, visualizzi le
tre sequenze divise per tipo.
Memorizzo le pari in un array, le dispari in un
secondo array e tutto il resto in un terzo,
controllando le dimensioni

*/

#include <stdio.h>   
#include <stdlib.h>
#include <string.h>

#define lung 10 
int main() {
	int p = 0, d = 0, a = 0, i = 0;
	char cosa, pari[lung], dispari[lung], altro[lung];

	do {
		scanf("%c", &cosa);
		fflush(stdin);

		switch (cosa) {
		case ' ':
			break;
		case '0':
		case '2':
		case '4':
		case '6':
		case '8':
			pari[p] = cosa;
			p++;
			break;
		case '1':
		case '3':
		case '5':
		case '7':
		case '9':
			dispari[d] = cosa;
			d++;
			break;
		default:
			altro[a++] = cosa;
			//altro[++a] = cosa; // errato

			break;
		}

		//if (cosa == '0' || cosa == '2' || cosa == '4' || cosa == '6' || cosa == '8') {
		//	pari[p] = cosa;
		//	p++;
		//}
		//if (cosa == '1' || cosa == '3' || cosa == '5' || cosa == '7' || cosa == '9') {
		//	dispari[d] = cosa;
		//	d++;
		//}
		//if (cosa!=' ' && 
		//	!(cosa == '1' || cosa == '3' || cosa == '5' || cosa == '7' || cosa == '9') &&
		//	cosa != '0' && cosa != '2' && cosa != '4' && cosa != '6' && cosa != '8'
		//	)
		//{
		//	altro[a++] = cosa;
		//}

	} while (cosa != ' '&& 
		p < lung && 
		d < lung && a < lung);


	printf("\nle cifre pari sono: ");
	for (i = 0; i < p; i++) printf(" %c ", pari[i]);

	printf("\nle cifre dispari sono: ");
	for (i = 0; i < d; i++) printf(" %c ", dispari[i]);

	printf("\ni caratteri non cifre sono: ");
	for (i = 0; i < a; i++) printf(" %c ", altro[i]);


	system("pause");
	return 0;
}


