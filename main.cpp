#include <cstdlib>
#include <cstdio>

typedef struct no {
	unsigned num;
	no *sae;
	no *sad;
} no;

typedef no * arv;

arv init() {
	return NULL;
}

bool arvoreVazia(arv arvore) {
	if (arvore == NULL)
		return true;
	else
		return false;	
}

void mostrarArvoreOrdem(arv arvore) {
	if (!arvoreVazia(arvore)) {
		mostrarArvoreOrdem(arvore->sae);
		printf("%i ", arvore->num);
		mostrarArvoreOrdem(arvore->sad);
	}
}

arv inserir (arv arvore, unsigned valor) {
	if (arvoreVazia(arvore)) {
		arv novo = new no;
		novo->num = valor;
		novo->sad = NULL;
		novo->sae = NULL;
		return novo;
	} else {
		if (valor > arvore->num)
			arvore->sad = inserir(arvore->sad, valor);
		else
			arvore->sae = inserir(arvore->sae, valor);
		return arvore;
	}
}

arv deletarTodasFolhas(arv arvore){
	if(arvoreVazia(arvore)){
		return NULL;
	}else{
		if(arvore->sae == NULL && arvore->sad == NULL){
			free(arvore);
			return NULL;
		}
		arvore->sae = deletarTodasFolhas(arvore->sae);
		arvore->sad = deletarTodasFolhas(arvore->sad);
		return arvore;
	}
}

int main () {
	arv raiz, temp = NULL;
	raiz = init();
	unsigned op, num;
	
	printf("\n Dymas Sousa e Vinicius Oliveira - Questao 04\n");
	
do {
		puts("\n");
		puts("1. Inserir numero           2. Mostrar arvore");
		puts("3. Remover folhas");
		puts("0. Sair");
		printf("digite uma opçao: ");
		scanf("%u", &op);
		switch (op) {
			case 1: {
				printf("\nDigite um numero: ");
				scanf("%u", &num);
				raiz = inserir(raiz,  num);
				break;
			}
			case 2: {
				if(arvoreVazia(raiz))
					printf("nenhum valor na arvore");
				else
					mostrarArvoreOrdem(raiz);	
				break;
			}
			case 3: {
				if(arvoreVazia(raiz))
					printf("nenhum valor na arvore");
				else
					raiz = deletarTodasFolhas(raiz);
				break;
			}
			case 0: {
				break;
			}
			default: {
				printf("valor invalido, tente novamente!");
				op = 4;
			}
		}
	}while (op >= 1 && op <= 3);
	
	
	return 0;
} 