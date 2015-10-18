/*
a)	Quanto vale mistero(7) e mistero(8)?
b)	Cosa calcola in generale la funzione mistero(x)?

*/
#include <stdio.h> 
#include <math.h>
#include <stdlib.h>

int mistero(int x){

	if(x>=1)
		return (x%2)+10*mistero(floor(x/2.0));
	else
		return 0;
}


int main(){
	int result;
	result = mistero(7);
	for(int i=0; i<=8; i++){
		result = mistero(i);
		printf("Risulatato %d\n", result);
	}
	system("pause");
	return 0;
}
