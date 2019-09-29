/*
Definiamo doppie le parole in cui la prima metà è identica alla seconda 
(esempi: cece, cancan, couscous) e assonanti le parole che sarebbero doppie
se non avessero l'ultima lettera (esempi: amami, marmara, porpora)

Si definisca una funzione  … doppia(…)  che riceve come parametro una stringa 
(che supponiamo valida e ben formata) e restituisce 1 se la stringa rappresenta
una parola doppia, 0 altrimenti

Si definisca una funzione  … assonante(…)  che riceve una stringa e restituisce
1 se la stringa rappresenta una parola assonante, 0 altrimenti. 

Si apprezzano, in particolare, soluzioni che riusano efficacemente la funzione definita al punto precedente
Si discuta (ed eventualmente si codifichi) una versione di …doppia(…) che faccia uso della ricorsione


*/

#include <stdio.h>
#include <string.h>
#include<stdlib.h>


int doppia(char parola[]){

	int len = strlen(parola);
	//non è dopia perchè dispari
	if(len%2!=0){
		return -1;
	}
	else{
		// ciclo su metà parola
		for(int i= 0; i<len/2; i++){
			// cerco differenze
			if(parola[i]!=parola[i+len/2]){
				return 0;
			}
		}
		// parola doppia
		return 1;
	}
} 

int assonante(char parola[]){
	char temp[100];
	strcpy(temp,parola);
	temp[strlen(temp)-1] = 0;
	return doppia(temp);

}

int main(){
	char parola[]="cacas";
	if (doppia(parola)==1)
		printf("%s - doppia \n",parola);
	if (assonante(parola)==1)
		printf("%s - assonante \n",parola);

	system("pause");
}