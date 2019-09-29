#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	main2();
	system("pause");
}


//------------tde 9-2-2010---------
int main1 () {
	char c, arr['z'-'a'], *pChar;
	int i, *pInt;
	int matr = 34 ; // inserire qui le ultime due cifre della propria matricola  
	//Inizio prima parte	
	for ( c='a'; c<'z'; c++) {
		arr[c-'a'] = c;
		printf("%c ", arr[c-'a']);
	}
	printf("\n");	
	//Inizio seconda parte
	pChar = arr + matr%15;
	for (i=0; i< 5; i++) {
		printf("%c ", *pChar);
		pChar++;
	}
	printf("\n");
	//Inizio terza parte	
	pInt = (int *)arr + matr%2;
	for (i=0; i<5; i++) {
		pChar = (char *)pInt;
		printf("%c ", *pChar);
		pInt++;
	}
	system("pause");
	return 0;
}


//------------tde 24-2-2011-----------------

int main2(){
	int c;
	c=f(2,3);
	printf ("c = %d\n", c);    
	c=f(4,2);
	printf ("c = %d\n", c);    
	c=f(2,4);
	printf ("c = %d\n", c);    
	c=f(3,3);
	printf ("c = %d\n", c);    
	c=f(5,1);
	printf ("c = %d\n", c);
}
int f(int d,int e){
	if( e > 0 )
		return f(d,e-1) + f(d,e-1);
	else
		return d;    
}

/*
(2,3)
(2,2)	     +		  (2,2)
[(2,1)+(2,1)]        +        [(2,1)+(2,1)]
{[(2,0)+(2,0)]+[(2,0)+(2,0)]}+{[(2,0)+(2,0)]+[(2,0)+(2,0)]}
{[  2  +  2  ]+[ 2   +  2  ]}+{[  2  +  2  ]+[ 2   +  2  ]}
[ 4   +  4  ]        +        [ 4   +  4  ] 
8              +              8
16 = 2^4 = 2*2^3


(3,3)
(3,2)	     +		  (3,2)
[(3,1)+(3,1)]        +        [(3,1)+(3,1)]
{[(3,0)+(3,0)]+[(3,0)+(3,0)]}+{[(3,0)+(3,0)]+[(3,0)+(3,0)]}
{[  3  +  3  ]+[ 3   +  3  ]}+{[  3  +  3  ]+[ 3   +  3  ]}
[ 6   +  6  ]        +        [ 6   +  6  ] 
12             +              12
24 = 3* 2^3
*/

//_----esempio----------------

// -----------  tde 7-9-2009 ----------

void foo(char * parola) {   // 19
	if (parola == NULL)
		return;
	else {
		printf("%c", *parola);
		parola=parola+1;      
		if(strlen(parola) == 0)
			return;
		else {
			foo(parola-1);   
			printf("%c", *parola);
			return;
		}
	}
}

int main3() {
	char m[7] = "623619";
	foo(m+4);
	printf("SE ARRIVO QUI HO FINITO\n");
	return 0;
}

// -------------tde 10-9-2010--------------

int f2( char * pcA, char * pcB, int * num ) {
	int valore=0;
	*num = *num + 1;                
	if ( pcA >= pcB )             
		return *num;                 
	else                        
		valore=f2( pcA+1, pcB-1, num );     
	if ( *pcA >= *pcB ) {         
		pcA = pcB;                
		*num = *num + 10;
	}
	printf("%c", *pcA);          
	return *num;                     
}
int main4() {
	char matricola[7] = "123456";         
	int cont = 0, val=0;
	printf("%s - ", matricola);       
	val=f2( matricola, matricola+5, &cont );     
	printf(" - %d - %d", cont, val);
	return 0;
}

// ----------------tde 24-2-2011-------------

int main6(){
    int c;
    c=f(2,3);
    printf ("c = %d\n", c);    
    c=f(4,2);
    printf ("c = %d\n", c);    
    c=f(2,4);
    printf ("c = %d\n", c);    
    c=f(3,3);
    printf ("c = %d\n", c);    
}

int f4(int d,int e){
    if( e > 0 )
        return f(d,e-1) + f(d,e-1);
    else
        return d;    
}



// -------------tde 8-2-2011----------

//#define M 16
//void main5(int k) {
//	int* h = (int*) malloc(sizeof(int) * M);
//	f3(h + M - 1, k, 0);
//	g1(h, M);
//	if (h) {
//		free(h);
//	}
//}
//void f3(int * a, int b, int c) {
//	if (c == M)
//		return;
//	c++;
//	*(a) = b % 2;
//	a--;
//	f3(a, b/2, c);
//}
//void g1(int* d, int e) {
//	if (e) {
//		printf("%d ",*d);
//		d++;
//		g1(d, e - 1);
//	} else
//		printf("\n");
//}	
