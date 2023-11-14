
#include <stdio.h>
#include <stdlib.h>
#include "Fd.h"

struct Elemento{
  int dado;
  elemento *prox;
};

struct fDinamic{
    elemento* inicio;
    elemento* fim;
    int tamanho;
};

Line* cria_line(){
    Line* l1 = (Line*)malloc(sizeof(Line));
    l1->fim == NULL;
    l1->inicio == NULL;
    l1->tamanho = 0;
    return l1;
}

elemento* cria_elemento(int numero){
    elemento* num = (elemento*)malloc(sizeof(elemento));
    num->dado = numero;
    return num;
}

int vazia(Line* l1){
    return (l1->inicio == NULL);
}

void inserir(Line* l1, elemento* num){
    if(l1->tamanho == 0){
        l1->inicio = num;
        l1->fim = num;
        num->prox = NULL;

    } else{
        l1->fim->prox = num;
        l1->fim = num;
        num->prox = NULL;
    }
    l1->tamanho++;
    printf("\n\nINSERIDO COM SUCESSO!!\n\n");
}

void desenfilera(Line* l1){
    elemento* aux = (elemento*)malloc(sizeof(elemento));
    if(vazia(l1))
         printf("\n\nWARNING: THE LINE IS EMPTY!!\n\n");
    else{
        aux = l1->inicio;
        l1->inicio = aux->prox;
        l1->tamanho--;
        printf("\n\nREMOVIDO COM SUCESSO\n\n");
    }

      free(aux);
}

void imprime(Line* l1){
    elemento* aux = (elemento*)malloc(sizeof(elemento));

    if(vazia(l1))
        printf("\n\nWARNING: THE LINE IS EMPTY!!\n\n");
    else{
        aux = l1->inicio;
        printf("\nLine: ");
        while(aux != NULL){
            printf(" %d", aux->dado);
            aux = aux->prox;
        }
    }
}

void libera_ela(Line* l1){
    free(l1);
}

int busca(Line* l1, elemento* numero){
    elemento* aux1 = (elemento*)malloc(sizeof(elemento));

    if(vazia(l1))
          printf("\n\nWARNING: THE LINE IS EMPTY!!\n\n");
    else{
        aux1 = l1->inicio;
        for(int i = 0; i < l1->tamanho; i++){
            if(numero->dado ==  aux1->dado)
                return i;
            aux1 = aux1->prox;
        }
    }

    return 1;
}

void isEmpty(Line* l1){
    if(vazia(l1)){
        printf("\n\nFILA VAZIA!");
    } else{
        printf("\n\nFILA NÃO ESTÁ VAZIA!");
    }
}

void del_elementos(Line* l1){
    if(vazia(l1))
         printf("\n\nWARNING: THE LINE IS EMPTY!!\n\n");
    else{
        for(int j = l1->tamanho; j > 0; j--){
            desenfilera(l1);
        }
        printf("\n\nFILA LIMPA COM SUCESSO!!");
        l1->tamanho = 0;
    }
}

int size(Line* l1){
    return l1->tamanho;
}

