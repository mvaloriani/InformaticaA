#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

//Modificare ora il programma precedente 
//facendo in modo che gli elementi dell’array 
// vengano ordinati in base all’età in ordine crescente 


#include <stdio.h> 
#include <string.h>
#include <stdlib.h>


#define MAX_PERS 4 
#define MAX_ETA 20 

typedef struct { int peso; int alt; int eta; } dati; 

int main() { 

	dati arch[MAX_PERS], temp; 
	int i, j; 

	// lettura dati
	for(i=0;i<MAX_PERS;i++) { 
		printf("Altezza: "); scanf("%d", &(arch[i].alt)); 
		printf("\nPeso: "); scanf("%d", &(arch[i].peso)); 
		printf("\nEta': "); scanf("%d", &(arch[i].eta));
	} 

	// ordinamento
	// scorro la lista di persone
	for(i=0;i<MAX_PERS-1;i++) { 
		//riscorro tutti gli elementi fino a quello attuale
		for(j=0;j<MAX_PERS-1-i;j++) { 
			// se l'elemento successivo è maggiore inverto i due elementi
			if(arch[j].eta > arch[j+1].eta) 
			{ 
				temp=arch[j+1]; 
				arch[j+1]=arch[j];
				arch[j]=temp; }
		}
	} 

	// visualizzazione
	printf("\n persone con eta' <= %d", MAX_ETA);
	for (i=0; i<MAX_PERS; i++) {
		if(arch[i].eta <= MAX_ETA) 
		{
			printf("\n %d, %d, %d", arch[i].alt, arch[i].peso, arch[i].eta); 
		}

		//else{
		//	break;
		//}
	}

	system("pause");
	return 0;
} 
