#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

/*
Due parole p e q si definiscono Hertzianamente compatibili
se entrambe sono leggibili anche “oscillando” e leggendo 
alternativamente i caratteri dell’una e dell’altra. 
La figura mostra tigre con fiera e fiera con fresa. 

Si noti anche che la relazione sussiste in due modi (diretto o inverso).
In figura: 
fiera
tigre 

si leggono iniziando dalla stessa lettera (modo diretto),

fiera
fresa 

occorre iniziare dall’iniziale dell’ “altra” parola nella 
coppia (modo inverso). 

Se la relazione fosse definita solo in modo diretto
o solo in modo inverso varrebbe anche la proprietà transitiva 
(esempio: aria, prua, erba, orma sono tutte direttamente compatibili tra loro),
ma consideriamo due parole compatibili indipendentemente
dal modo in cui la proprietà si manifesta. 

Si scriva un programma che verifica la compatibilità Hertziana di due stringhe.

*/

#include <stdio.h>   
#include <stdlib.h>
#include <string.h>

#include <stdio.h>
#define N 100
int main() {
	char str1[N], str2[N];
	int i = 0, j = 0, lun1, lun2, compatibili;
	printf("Inserire due stringhe\n");
	scanf("%s", str1);
	scanf("%s", str2);
	lun1 = strlen(str1);
	lun2 = strlen(str2);
	
	if (lun1 != lun2)
		printf("Stringhe non compatibili");
	
	else {
		// codice che verifica direttamente compatibili
		compatibili = 1;
		for (i = 1; i < lun1 && compatibili; i = i + 2) {
			if (str1[i] != str2[i])
				compatibili = 0;
		}
		if (compatibili == 1)
			printf("str1 e str2 direttamente compatibili");
		else
			printf("str1 e str2 non direttamente compatibili");
		// codice che verifica inversamente compatibili
		compatibili = 1;
		for (i = 0; i < lun1 && compatibili; i = i + 2) {
			if (str1[i] != str2[i])
				compatibili = 0;
		}
		if (compatibili == 1)
			printf("str1 e str2 inversamente compatibili");
		else
			printf("str1 e str2 non inversamente compatibili");
	
	
	}
	/*else {
		bool inv=true, dir = true;
		
		for (i = 0; i < lun1 && (inv || dir); i++) {
			if (i % 2 == 0 && str1[i] != str2[i]) {
				inv = false;
			}
			if (i % 2 != 0 && str1[i] != str2[i]) {
				dir = false;
			}
		}

		if (inv)
			printf("str1 e str2 inversamente compatibili\n");
		if (dir)
			printf("str1 e str2 diretta compatibili\n");
		if (dir==false && inv==false)
			printf("str1 e str2 non compatibili\n");

	}*/
	

	system("pause");
	return 0;
}



