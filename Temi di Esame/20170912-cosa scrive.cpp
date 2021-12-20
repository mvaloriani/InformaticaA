//Si dica cosa stampa il seguente codice


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int foo(char* x, char* y, int k) {
    if (!k)
        printf(" & ");
    else {
        printf("%c", y[k % 2]);
        k = foo(x, y, k - 1);
        printf("%c", y[k % 2]);
        k++;
    }
    return k;
}


int main() {
    int i = 3;

    char x[] = "MV", y[] = "AI";
    i++;
    printf("%c", x[i % 2]);
    i = foo(x, y, i - 1);

    return 0;
}
