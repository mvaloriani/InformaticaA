#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

// Scrivere un programma C che legge un vettore
//di lunghezza arbitraria 
// e stampa 1 se il vettore contiene
//solo valori diversi, 0 altrimenti.

#include <stdio.h> 
#define n 15 



int main() {
	int i=0, j=0, t=0, si = 1;

	int v[n] = {0,1,0,1, 2,3,4};
	
	char input;

	
	printf("Inserire un vettore di interi di dimensione %d\n", n);
	for (i = 0; i < n; i++)
		scanf("%d", &v[i]);


	//while (i<n && continuo)
	//{
	//	scanf("%c", &input);
	//	if (input != 'C') {
	//		scanf("%d", &v[i]);
	//		t= i++;
	//		
	//	}
	//	else
	//		continuo=false;
	//}

	// Soluzione con piu cicli
	for (i = 0; (i < n - 1); i++) {

		for (j = i + 1; j < n; j++) {
			if (v[i] == v[j]) {
				si = 0;

			}
		}
	}

	//// soluzione ottima   
	for (i = 0; (i < n - 1) && si!=0 ; i++) {
		for (j = i + 1; j < n && si != 0; j++) {
			if (v[i] == v[j]) {
				si = 0;				
			}
		}
	}

	////  soluzione brutta
	//for (i = 0; (i < n - 1); i++) {
	//	for (j = i + 1; j < n; j++) {
	//		if (v[i] == v[j]) {
	//			si = 0;
	//			break;
	//		}
	//	}
	//	if(si==0)
	//		break;
	//}

	//// Solzione intermedia
	//for (i = 0; (i < n - 1); i++) {
	//	for (j = i + 1; j < n; j++) {
	//		if (v[i] == v[j]) {
	//			printf("0\n", si);
	//			return 0;
	//		}
	//	}
	//}

	
	
	printf("%d\n", si);
	return 0;
}
