#include <stdio.h>
#include <stdlib.h>
#include "duplamenteencadeada.h"

struct Elemento{
  int dado;
  elemento *ante;
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
    num->ante = NULL;
    num->pro = NULL;
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
        elemento * aux = (elemento*) malloc(sizeof(elemento));
        aux = q->fim;
        num->ante = aux;
        aux->pro = num;
        q->fim = num;
    }
    q->tam++;
    return 0;
}

int remover(lista* q){
    elemento* aux = (elemento*)malloc(sizeof(elemento));
    if(vazia(q))
         return -1;
    else{
        if(q->tam == 1){
        aux->ante = NULL;
        aux->pro = NULL;
        aux->dado = NULL;
        q->ini = NULL;
        q->fim = NULL;
        q->tam--;
        return 0;
        }

        aux = q->ini;
        q->ini = aux->pro;
        q->ini->ante = NULL;
        q->tam--;
        return 0;
    }

      free(aux);
}

int remove_(lista* q,int valor){
    elemento* aux1 = (elemento*)malloc(sizeof(elemento));
    elemento* aux2 = (elemento*)malloc(sizeof(elemento));
    if(vazia(q))
         return -1;
    else{
        aux1 = q->ini;

        if(q->tam == 1){
        aux1->ante = NULL;
        aux1->pro = NULL;
        aux1->dado = NULL;
        q->ini = NULL;
        q->fim = NULL;
        q->tam--;
        return 0;
        }

        if(q->ini == q->fim){
            q->ini = NULL;
            q->fim = NULL;
        }

        if(q->ini->dado == valor){
        q->ini = aux1->pro;
        q->ini->ante = NULL;
        q->tam--;
        return 0;
        }

        while(aux1 != q->fim && aux1->dado != valor){
                aux1 = aux1->pro;
                if(valor == aux1->dado){
                aux2 = aux1->ante;
                aux2->pro = aux1->pro;
                aux2 = aux1->pro->ante;
                aux2->ante = aux1->ante->ante;
                q->tam--;

                aux1->ante = NULL;
                aux1->pro = NULL;
                aux1->dado = NULL;

                return 0;
            }
        }
    }
}

void imprime(lista* q){
    elemento* aux = (elemento*)malloc(sizeof(elemento));

    if(vazia(q))
        printf("Erro: lista vazia!\n");
    else{
        int cont = 0;
        aux = q->ini;
        printf("Lista: ");
        while(cont != q->tam){
            printf(" %d", aux->dado);
            aux = aux->pro;
            cont ++;
        }
    }
}

int find(lista* q, elemento* num){
    elemento* aux = (elemento*)malloc(sizeof(elemento));

    if(vazia(q))
          printf("Erro: lista vazia!\n");
    else{
        aux = q->ini;
        for(int i = 0; i < q->tam; i++){
            if(num->dado == aux->dado){
                return i;
            }
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
