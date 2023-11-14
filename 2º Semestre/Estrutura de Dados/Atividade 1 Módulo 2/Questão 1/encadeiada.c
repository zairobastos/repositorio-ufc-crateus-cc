#include <stdio.h>
#include <stdlib.h>
#include "encadeiada.h"

struct Elemento{
  int dado;
  elemento *pro;
};

struct Lista{
    elemento* ini;
    elemento* fim;
    int tam;
};

lista* create(){
    lista* q = (lista*)malloc(sizeof(lista));
    q->fim == NULL;
    q->ini == NULL;
    q->tam = 0;
    return q;
}

elemento* createElemento(int n){
    elemento* num = (elemento*)malloc(sizeof(elemento));
    num->dado = n;
    return num;
}

int vazia(lista* q){
    return (q->ini == NULL);
}

int size(lista* q){
    return q->tam;
}

int isEmpty(lista* q){
    if(vazia(q)){
        return 0;
    } else{
        return -1;
    }
}

int add(lista* q, elemento* num){
    if(q->tam == 0){
        q->ini = num;
        q->fim = num;
        num->pro = NULL;

    } else{
        q->fim->pro = num;
        q->fim = num;
        num->pro = NULL;
    }
    q->tam++;
    return 0;
}

int remover(lista* q){
    elemento* aux = (elemento*)malloc(sizeof(elemento));
    if(vazia(q))
         return -1;
    else{
        aux = q->ini;
        q->ini = aux->pro;
        q->tam--;
        return 0;
    }

      free(aux);
}

void imprime(lista* q){
    elemento* aux = (elemento*)malloc(sizeof(elemento));

    if(vazia(q))
        printf("Erro: lista vazia!\n");
    else{
        aux = q->ini;
        printf("Lista: ");
        while(aux != NULL){
            printf(" %d", aux->dado);
            aux = aux->pro;
        }
    }
}

int find(lista* q, elemento* num){
    elemento* aux = (elemento*)malloc(sizeof(elemento));

    if(vazia(q))
          return -1;
    else{
        aux = q->ini;
        for(int i = 0; i < q->tam; i++){
            if(num->dado ==  aux->dado)
                return i;
            aux = aux->pro;
        }
        return -1;
    }
}

int clear(lista* q){
    if(vazia(q))
         return -1;
    else{
        for(int j = q->tam; j > 0; j--){
            remover(q);
        }
        return 0;
        q->tam = 0;
    }
}

