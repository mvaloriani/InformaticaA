/*
Scrivere una funzione "pulisci" che, data una lista i cui elementi sono liste di interi, elimina tutte le sottoliste che contengono valori ripetuti.

Si consiglia di utilizzare funzioni ausiliarie per inserimenti e cancellazioni e distruzioni di liste, come illustrato a lezione e nella dispensa.

Scrivere le funzioni necessarie per svolgere l'esercizio subito dopo il main e prima delle funzioni fornite.

Output atteso:
Lista (ogni elemento in una riga)
5 ---> 4 ---> 1 ---> 5 ---> 2 ---> 7 ---> ---|
1 ---> 6 ---> 9 ---> 1 ---> 5 ---> 7 ---> 9 ---> 0 ---> ---|
1 ---> 5 ---> 1 ---> 1 ---> 2 ---> 8 ---> 9 ---> 0 ---> ---|
1 ---> 3 ---> 2 ---> 4 ---> 0 ---> 9 ---> 8 ---> 6 ---> ---|
1 ---> 2 ---> 9 ---> 8 ---> 4 ---> 0 ---> 9 ---> 0 ---> ---|
1 ---> 8 ---> 7 ---> 8 ---> 3 ---> ---|
1 ---> 3 ---> 4 ---> 2 ---> 5 ---> 7 ---> 9 ---> 0 ---> ---|
7 ---> 8 ---> 9 ---> ---|

Lista dopo pulizia
1 ---> 3 ---> 2 ---> 4 ---> 0 ---> 9 ---> 8 ---> 6 ---> ---|
1 ---> 3 ---> 4 ---> 2 ---> 5 ---> 7 ---> 9 ---> 0 ---> ---|
7 ---> 8 ---> 9 ---> ---|

Il file C di partenza è scaricabile da qui:
https://www.dropbox.com/s/igrmcvv5tk67rbg/lab7es2.c?dl=0

Enter your answer
3.Si considerino i seguenti tipi di dato atti a rappresentare i prodotti di un supermercato:
typedef struct { int giorno, mese, anno; } data
typedef struct ELP {
    char nome[50];
    data giorno_scadenza;
    struct ELP * next;
} NodoP;
typedef NodoP * ListaP;
typedef struct ELS {
     ListaP prodotti;
     struct ELS * next;
} NodoS;
typedef NodoS * ListaS;
Un supermercato è rappresentato da una lista di scaffali (ListaS), ed ogni scaffale (NodoS) contiene a sua volta una lista di prodotti (ListaP). Un prodotto (NodoP) è caratterizzato da un nome e da un giorno di scadenza.

Si scriva una funzione eliminaScaduti che riceve in ingresso una lista di scaffali ed una data G rappresentante un giorno dell’anno e che modifica la lista in ingresso eliminando dagli scaffali tutti i prodotti il cui giorno di scadenza è antecedente al giorno G in ingresso (se una scaffale resta vuoto lo si lasci pure come lista vuota).

Per risolvere l'esercizio si sviluppi e si invochi la funzione ausiliaria
int primaDi(Data d1, Data d2)
che restituisce 1 se d1 è una data antecedente alla data d2, 0 altrimenti.
*/