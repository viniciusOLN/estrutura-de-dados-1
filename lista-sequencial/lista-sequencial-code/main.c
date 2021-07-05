#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define TAM 20

typedef struct {
    int itens[TAM];
    int n; // a quantidade de itens
} Lista;


void gera (Lista *list) {
    for(list->n = 0; list->n < TAM; list->n = list->n + 1)
        list->itens[list->n] = 1 + rand() % 100;
}


void iniciar(Lista *list) {
    list->n = 0;
}


void mostra(Lista *list) {
    for (int i = 0; i < list->n; i++)
        printf("%i ", list->itens[i]);
}


void inserirFim(Lista *list, int v) {
    if (list->n < TAM) {
        list->itens[list->n] = v;
        list->n = list->n + 1;
    }
}

void inserirIni(Lista *list, int v) {
 int i;
    if (list->n < TAM) {
        for(i = list->n; i > 0; --i)
            list->itens[i] = list->itens[i-1];
    list->itens[i] = v;
    list->n = list->n + 1;
    }
}


void inserirPos(Lista *list, int v, int pos) {
 int i;
    if (list->n < TAM) {
        for(i = list->n; i >= pos; i--)
            list->itens[i] = list->itens[i-1];
    list->itens[i] = v;
    list->n = list->n + 1;
    }
}


void removerFim(Lista *list) {
    list->n = list->n - 1;
}


void removerIni(Lista *list) {
    for(int i = 1; i < list->n; i++)
        list->itens[i-1] = list->itens[i];
list->n = list->n - 1;
}


int main () {
Lista lista;
iniciar(&lista);
srand((unsigned) time(NULL));
gera(&lista);
puts(""); mostra(&lista);
removerFim(&lista);
removerIni(&lista);
removerFim(&lista);
removerIni(&lista);
inserirPos(&lista, 3, 3);
puts(""); mostra(&lista);
return 0;
}
