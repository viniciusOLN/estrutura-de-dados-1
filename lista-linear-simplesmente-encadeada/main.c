#include <stdio.h>
#include <stdlib.h>

typedef struct STRING *string;

typedef struct {
    char *placa;
    struct ItemDaLista *proximoItem;
    struct ItemDaLista *anteriorItem;
}ItemDaLista;

typedef struct {
  int quantItens;
  ItemDaLista *primeiroDaLista;
  ItemDaLista*ultimoDaLista;
} Lista;

void initLista(Lista *lista){
    lista->quantItens = 0;
    lista->primeiroDaLista = NULL;
    lista->ultimoDaLista = NULL;
}

void inserirPrimeiro(Lista *lista, char *valor){
  ItemDaLista *novo;
  novo = malloc(sizeof(ItemDaLista));
  novo->placa = valor;
  novo->proximoItem = lista->primeiroDaLista;
  lista->primeiroDaLista = novo;
  if (lista->quantItens == 0)
    lista->ultimoDaLista = novo;
  lista->quantItens++;
}

void inserirUltimo(Lista *lista, char *valor){
    ItemDaLista *novo;;
    novo = malloc(sizeof(ItemDaLista));
    novo->placa = valor;
    novo->proximoItem = NULL;
    if(lista->quantItens == 0){
        lista->primeiroDaLista = novo;
        lista->ultimoDaLista = novo;
    }else{
        lista->ultimoDaLista->proximoItem = novo;
        lista->ultimoDaLista = novo;
    }
    lista->quantItens++;
}

void mostrarLista(Lista *lista){
 ItemDaLista *i = lista->primeiroDaLista;
  while(i != NULL){
    printf("%s ",  i->placa);
    i = i->proximoItem;
  }
}

int main(){
    Lista *lista;
    //char *arg = (char *) malloc(50 * sizeof(char));
    //scanf("%s", arg);
    char arg[] = "alo";
    initLista(&lista);
    inserirUltimo(&lista, arg);
    inserirPrimeiro(&lista, arg);
    inserirUltimo(&lista, arg);
    inserirPrimeiro(&lista, arg);
    inserirUltimo(&lista,  arg);
    mostrarLista(&lista);

 return 0;
}
