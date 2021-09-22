#include <stdio.h>
#include <stdlib.h>
#define velMAX 40

typedef struct ItemDaLista{
    int placa;
    int velocidade;
    int dia;
    int mes;
    int ano;
	int valor_multa;
    struct ItemDaLista *proxItem;
}ItemDaLista;

typedef struct Lista{
    int quantItens;
    ItemDaLista *primeiroElemento;
}Lista;

void initLista(Lista *lista){
    lista->quantItens = 0;
    lista->primeiroElemento = NULL;
}

<<<<<<< Updated upstream
void inserirPrimeiro(Lista *lista, ItemDaLista valor){
    ItemDaLista *aux = malloc(sizeof(ItemDaLista));
    aux->velocidade = valor.velocidade;
    aux->placa = valor.placa;
    aux->dia = valor.dia;
    aux->mes = valor.mes;
    aux->ano = valor.ano;
    aux->valor_multa = 0;
    if(aux->velocidade > velMAX){
     int temp = (aux->velocidade - velMAX) * 5;
        if(temp >= 190)
          aux->valor_multa = 190;
        else
          aux->valor_multa = temp;
    }

    aux->proxItem = NULL;
    if(lista->quantItens == 0){
        lista->primeiroElemento = aux;
    }else{
        aux->proxItem = lista->primeiroElemento;
        lista->primeiroElemento = aux;
    }
    lista->quantItens++;
}

void inserirUltimo(Lista *lista, ItemDaLista valor){
    ItemDaLista *aux = malloc(sizeof(ItemDaLista));
    aux->velocidade = valor.velocidade;
    aux->placa = valor.placa;
    aux->dia = valor.dia;
    aux->mes = valor.mes;
    aux->ano = valor.ano;
    aux->valor_multa = 0;
    if(aux->velocidade > velMAX){
     int temp = (aux->velocidade - velMAX) * 5;
        if(temp >= 190)
          aux->valor_multa = 190;
        else
          aux->valor_multa = temp;
=======
void inserirUltimo(Lista *lista, char motorista, int velocidade, int dia, int mes, int ano){
    ItemDaLista *novo;;
    novo = malloc(sizeof(ItemDaLista));

    novo->placa = motorista;
    novo->velocidade = velocidade;

    novo->dia = dia;
    novo->mes = mes;
    novo->ano = ano;
>>>>>>> Stashed changes

    }

    aux->proxItem = NULL;
    if(lista->quantItens == 0){
        lista->primeiroElemento = aux;
    }else{
        ItemDaLista *temp = lista->primeiroElemento;
        while(1){
            if(temp->proxItem == NULL){
                temp->proxItem = aux;
                break;
            }
            temp = temp->proxItem;
        }
     }
     lista->quantItens++;
}

<<<<<<< Updated upstream
void removerPrimeiro(Lista *lista){
   ItemDaLista *aux = lista->primeiroElemento->proxItem;
   lista->primeiroElemento = aux;
   lista->quantItens--;
}

void removerUltimo(Lista *lista){
  ItemDaLista *ultimo = lista->primeiroElemento;
  ItemDaLista *penultimo = lista;

  while(ultimo->proxItem != NULL){
	  penultimo = ultimo;
	  ultimo = ultimo->proxItem;
  }
  penultimo->proxItem = NULL;
  lista->quantItens--;
}

void mostrarLista(Lista *lista){
ItemDaLista *temp = lista->primeiroElemento;
  while(temp != NULL){
    printf("placa: %d velocidade: %d data: %d/%d/%d valor da multa: %d\n0", temp->placa, temp->velocidade, temp->dia, temp->mes, temp->ano, temp->valor_multa);
    temp = temp->proxItem;
=======
void ler_valor(char *motorista, int *velocidade, int *dia, int *mes, int *ano){
    printf("digite a placa: ");
    scanf("%s", &motorista);
    printf("digite a velocidade: ");
    scanf("%i", &velocidade);
    printf("digite a data(dd/mm/aa): ");
    scanf("%i %i %i",&dia, &mes, &ano );;
}

void mostrarLista(Lista *lista){
 ItemDaLista *i = lista->primeiroDaLista;
  while(i != NULL){
        printf("aaaaaa");
    printf("placa: %s  velocidade: %i \n", i->placa, i->velocidade);
    i = i->proximoItem;
>>>>>>> Stashed changes
  }
}

int main(){
    Lista *lista;
<<<<<<< Updated upstream
    int op = 0;
    int exit = 0;
    initLista(&lista);
    do{
        puts("1. inserir no primeiro   2. inserir no ultimo");
        puts("3. mostrar lista   4. sair 5. remover primeiro");
        printf("digite uma opcao: ");
        scanf("%i", &op);
    	switch(op){
			case 1:{
	  		  ItemDaLista a;
	          printf("digite a placa: ");
	          scanf("%i", &a.placa);
	          printf("digite a velocidade: ");
	          scanf("%i", &a.velocidade);
	          printf("digite o dia: ");
	          scanf("%i", &a.dia);
	          printf("digite o mes: ");
	          scanf("%i", &a.mes);
	          printf("digite o ano: ");
	          scanf("%i", &a.ano);
	   	  	  inserirPrimeiro(&lista, a);
	   	  	  break;
	  		}
	   	    case 2:{
	  	 	  ItemDaLista a;
	          printf("digite a placa: ");
	          scanf("%i", &a.placa);
	          printf("digite a velocidade: ");
	          scanf("%i", &a.velocidade);
	          printf("digite o dia: ");
	          scanf("%i", &a.dia);
	          printf("digite o mes: ");
	          scanf("%i", &a.mes);
	          printf("digite o ano: ");
	          scanf("%i", &a.ano);
	          inserirUltimo(&lista, a);
	          break;
		    }
	        case 3:{
	        	mostrarLista(&lista);
	        	break;
	        }
	        case 4:{
	        	exit = 0;
	        	break;
	        }
	        case 5:{
				removerPrimeiro(&lista);
				break;
			}
	        default:{
	        	exit = 0;
	  	    }
		}
    }while(exit != 0);
    return 0;
=======
    char motorista[20];
    int velocidade;
    int dia;
    int mes;
    int ano;
    //printf("velocidade maxima permitida: %i\n", v_max);


    //ItemDaLista a;

    initLista(&lista, v_max);
    ler_valor(&motorista, &velocidade, &dia, &mes, &ano);
    char placa[23] = "aaada";
    dia = 10;
    velocidade = 200;
    mes = 12;
    ano = 2021;
    inserirUltimo(&lista, placa, velocidade, dia, mes, ano);
    mostrarLista(&lista);
 return 0;
>>>>>>> Stashed changes
}
