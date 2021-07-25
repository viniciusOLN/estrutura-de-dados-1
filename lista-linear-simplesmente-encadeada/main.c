#include <stdio.h>
#include <stdlib.h>
#define v_max 40

typedef struct {
    char *placa;
    int velocidade;
    int dia;
    int mes;
    int ano;
    int valor_multa;
    struct ItemDaLista *proximoItem;
}ItemDaLista;

typedef struct {
  int quantItens;
  int velocidade_max;
  ItemDaLista *primeiroDaLista;
  ItemDaLista*ultimoDaLista;
} Lista;

void initLista(Lista *lista, int velocidade){
    lista->quantItens = 0;
    lista->primeiroDaLista = NULL;
    lista->velocidade_max = velocidade;
    lista->ultimoDaLista = NULL;
}

void inserirUltimo(Lista *lista, ItemDaLista a){
    ItemDaLista *novo;;
    novo = malloc(sizeof(ItemDaLista));

    novo->placa = a.placa;
    novo->velocidade = a.velocidade;

    novo->dia = a.dia;
    novo->mes = a.mes;
    novo->ano = a.ano;

    if(novo->velocidade > lista->velocidade_max){
        int aux = (novo->velocidade - lista->velocidade_max);
        for(int i = 0; i < aux; i++){
         novo->valor_multa = novo->valor_multa + 5;
          if(novo->valor_multa > 190){
             novo->valor_multa = novo->valor_multa - 5;
             break;
          }
        }
    }

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

ItemDaLista ler_valor(){
    char motorista[20];
    ItemDaLista r;

    printf("digite a placa: ");
    scanf("%s", r.placa);
    printf("digite a velocidade: ");
    scanf("%i", &r.velocidade);
    printf("digite a data(dd/mm/aa): ");
    scanf("%i %i %i",&r.dia, &r.mes, &r.ano );;

    return r;
}

void mostrarLista(Lista *lista){
 ItemDaLista *i = lista->primeiroDaLista;
  while(i != NULL){
    printf("placa: %s velocidade: %i data: %i/%i/%i valor multa: %i \n",  i->placa, i->velocidade, i->dia, i->mes, i->ano, i->valor_multa);
    i = i->proximoItem;
  }
}

int main(){
    Lista *lista;
    //printf("velocidade maxima permitida: %i\n", v_max);

    ItemDaLista a;

    initLista(&lista, v_max);
    ItemDaLista b = ler_valor();
    inserirUltimo(&lista, b);
    mostrarLista(&lista);

 return 0;
}
