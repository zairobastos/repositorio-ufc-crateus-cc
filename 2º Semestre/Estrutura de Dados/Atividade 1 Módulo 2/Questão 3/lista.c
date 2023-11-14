#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct Lista{
    int *A;
    int ini;
    int fim;
};

int tam;

lista * inicializaLista(){
    lista * a = (lista*) malloc(sizeof(lista));
    return a;
}

void create(lista *a,int n){
    a->A[n];
    tam=n;
    printf("Lista criada com sucesso!\n");
}

void ini(lista *a){
    a->fim=0;
    a->ini=0;
}

int vazia(lista *a){
    return a->fim == a->ini;
}

int cheia(lista *a){
    return a->fim ==tam;
}

int isFull(lista *a){
    if(cheia(a)){
        return 0;
    }
    else {
        return -1;
    }
}

int isEmpty(lista *a){
    if(vazia(a)){
        return 0;
    }
    else{
        return -1;
    }
}

int size(lista *a){
    return (a->fim-a->ini);
}

int add(lista *a,int e){
    if(cheia(a)){
        return 1;
        printf("Lista cheia!\n");
    }
    else{
        a->A[a->fim] = e;

        if(a->fim != 0){
            for(int i=a->ini;i<a->fim;i++){
                for(int j=i;j<=a->fim;j++){
                    if(a->A[i] > a->A[j]){
                        int aux;
                        aux = a->A[j];
                        a->A[j] = a->A[i];
                        a->A[i] = aux;
                    }
                }
            }
        }
        a->fim ++;
        return 0;
    }
}

int remover(lista *a,int e){
    if(vazia(a)){
        return -1;
    }
    else{
        int cont;
        for(int i=a->ini;i<a->fim;i++){
            if(a->A[i] == e){
                cont = 1;
            }
            if(cont == 1){
                a->A[i]=a->A[i+1];
            }
        }
        if(cont == 1){
            a->fim --;
            return 0;
        }
    }
}

void imprime(lista *a){
    if(vazia(a)){
        printf("Erro: lista vazia.");
    }
    else{
        for(int i=a->ini;i<a->fim;i++){
        printf("%d\n",a->A[i]);
    }
    }
}

int linearSearch(lista *a,int e){
    for(int i=a->ini;i<a->fim;i++){
        if(a->A[i]==e){
            return i;
        }
    }
    return -1;

}

int bynarySearch(lista *a,int e){
    int esquerda=a->ini;
    int direita=a->fim;

    while(esquerda<=direita){
        int meio = (esquerda+direita)/2;

        if(a->A[meio]==e){
            return meio;
        }
        else if(a->A[meio]>e){
            direita=meio - 1;
        }
        else{
            esquerda=meio + 1;
        }
    }
    return -1;
}

void clear(lista *a){
    for(int i=a->ini;i<a->fim;i++){
        a->A[i]=0;
    }
    a->fim=a->ini;
    printf("Lista vazia!\n");
}





