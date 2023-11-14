#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

arvoreBI * create(){
    arvoreBI * arv = (arvoreBI *) malloc(sizeof(arvoreBI));
    if(arv != NULL){
        arv->raiz = NULL;
    	arv->tam = 0;
    	arv->nivel = 0;
    }
    return arv;
}

No * createRoot(arvoreBI *arv,int valor){
    arv->raiz = (No*) malloc(sizeof(No));

    if(arv->raiz != NULL){
        arv->raiz->filhoEsquerda = NULL;
        arv->raiz->filhoDireita = NULL;
        arv->raiz->valor = valor;
        arv->tam ++;
    }
    return arv->raiz;
}



No * add(arvoreBI * arv,No *raiz,int valor){
    No * aux = (No*) malloc(sizeof(No));
    if(aux != NULL){
        aux->filhoEsquerda = NULL;
        aux->filhoDireita = NULL;
        aux->valor = valor;

        if(raiz->filhoEsquerda != NULL && raiz->filhoDireita!= NULL && raiz->valor > valor){
            add(arv,raiz->filhoEsquerda,valor);
        }

        else if(raiz->filhoEsquerda != NULL && raiz->valor > valor){
            add(arv,raiz->filhoEsquerda,valor);
        }

        else if(raiz->filhoEsquerda != NULL && raiz->filhoDireita!= NULL && raiz->valor < valor){
            add(arv,raiz->filhoDireita,valor);
        }

        else if(raiz->filhoDireita != NULL && raiz->valor < valor){
            add(arv,raiz->filhoDireita,valor);
        }

        else if(raiz->filhoEsquerda == NULL && raiz->filhoDireita == NULL){

        if(raiz->valor > valor){
            raiz->filhoEsquerda = aux;
            arv->tam ++;
        }
        else if(raiz->valor < valor){
            raiz->filhoDireita = aux;
            arv->tam ++;
        }
        }

        else if(raiz->filhoEsquerda != NULL && raiz->filhoDireita == NULL){

        if(raiz->valor > valor){
            raiz->filhoEsquerda = aux;
            arv->tam ++;
        }
        else if(raiz->valor < valor){
            raiz->filhoDireita = aux;
            arv->tam ++;
        }
        }
    }
}

void clear(arvoreBI * arv){
	arv->raiz->filhoDireita = NULL;
	arv->raiz->filhoDireita = NULL;
	arv->raiz = NULL;
	arv->tam = 0;
	printf("Limpo com sucesso!\n\n");
}

int isEmpty(arvoreBI * arv){
	if(arv->raiz == NULL){
		return 0;
	}
	else{
		return -1;
	}
}

int size(arvoreBI * arv){
	return arv->tam;
}

int find_aux(arvoreBI * arv,No *raiz,int valor){

	No * aux= (No*) malloc(sizeof(No));
    aux->valor = valor;
    arv->nivel += 1;

	if (raiz == NULL) {
   		return -1;
	}
	else{
        if(raiz->valor == aux->valor){
            arv->nivel --;
            printf("Find: %d\n",arv->nivel);
        }

        else if(raiz->filhoEsquerda != NULL && raiz->filhoDireita!= NULL && raiz->valor > aux->valor){
            find_aux(arv,raiz->filhoEsquerda,valor);
        }

        else if(raiz->filhoEsquerda != NULL && raiz->valor > aux->valor){
            find_aux(arv,raiz->filhoEsquerda,valor);
        }

        else if(raiz->filhoEsquerda != NULL && raiz->filhoDireita!= NULL && raiz->valor < aux->valor){
            find_aux(arv,raiz->filhoDireita,valor);
        }

        else if(raiz->filhoDireita != NULL && raiz->valor < aux->valor){
            find_aux(arv,raiz->filhoDireita,valor);
        }

        else if(raiz->filhoEsquerda == NULL && raiz->filhoDireita == NULL){
            arv->nivel == 0;
            find_aux(arv,arv->raiz,valor);
        }

	}

}

void find(arvoreBI *arv,int valor) {
   find_aux(arv,arv->raiz,valor);
}

void printAllPre_aux(No *raiz) {
		if (raiz != NULL) {
			printf("%d\n", raiz->valor);
			printAllPre_aux(raiz->filhoEsquerda);
			printAllPre_aux(raiz->filhoDireita);
		}
	}

void printAllPre(arvoreBI *arv) {
    printAllPre_aux(arv->raiz);
}

void printAllIn_aux(No *raiz) {
		if (raiz != NULL) {
			printAllIn_aux(raiz->filhoEsquerda);
			printf("%d\n", raiz->valor);
			printAllIn_aux(raiz->filhoDireita);
		}
	}

void printAllIn(arvoreBI *arv) {
    printAllIn_aux(arv->raiz);
}

void printAllPost_aux(No *raiz) {
		if (raiz != NULL) {
			printAllPost_aux(raiz->filhoEsquerda);
			printAllPost_aux(raiz->filhoDireita);
			printf("%d\n", raiz->valor);
		}
	}

void printAllPost(arvoreBI *arv) {
    printAllPost_aux(arv->raiz);
}
