#include <stdio.h>
#include <stdlib.h>
#include "repositorio.h"

struct Repositorio{
    int *A;
    int *D;
    int ini;
    int fim;
};

int tam;

repositorio * inicializaLista(){
    repositorio * a = (repositorio*) malloc(sizeof(repositorio));
    return a;
}

void create(repositorio *a,int n){
    a->A[n];
    a->D[n];
    tam=n;
    printf("Repositorio criada com sucesso!\n");
}

void ini(repositorio *a){
    a->fim=0;
    a->ini=0;
}

int vazia(repositorio *a){
    return a->fim == a->ini;
}

int cheia(repositorio *a){
    return a->fim ==tam;
}

int estaCheio(repositorio *a){
    if(cheia(a)){
        return 0;
    }
    else {
        return -1;
    }
}

int estaVazio(repositorio *a){
    if(vazia(a)){
        return 0;
    }
    else{
        return -1;
    }
}

int tamanho(repositorio *a){
    return (a->fim-a->ini);
}

int add(repositorio *a,int e,int c){
    if(cheia(a)){
        return 1;
        printf("Repositorio cheio!\n");
    }
    else{
        a->A[a->fim] = c;
        a->D[a->fim] = e;

        if(a->fim != 0){
            for(int i=a->ini;i<a->fim;i++){
                for(int j=i;j<=a->fim;j++){
                    if(a->A[i] > a->A[j]){
                        int aux1,aux2;
                        aux1 = a->A[j];
                        aux2 = a->D[j];
                        a->A[j] = a->A[i];
                        a->A[i] = aux1;
                        a->D[j] = a->D[i];
                        a->D[i] = aux2;
                    }
                }
            }
        }
        a->fim ++;
        return 0;
    }
}

int tratar(repositorio *a){
int cont = 0,aux;
    for(int i=a->ini;i<a->fim;i++){
        for(int j=a->ini;j<a->fim;j++){
            if(a->A[i] > a->A[j]){
                cont ++;
                if(cont == a->fim){
                    aux=i;
                    a->fim --;
                    for(i = aux;i < a->fim; i++){
                        a->A[i] = a->A[i+1];
                    }
                    return a->A[aux];
                }
            }
        }
    }
}

int remover(repositorio *a,int e){
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

void imprime(repositorio *a){
    if(vazia(a)){
        printf("Erro: lista vazia.");
    }
    else{
        for(int i=a->ini;i<a->fim;i++){
        printf("O codigo e:%d  e o valor e:%d\n",a->D[i],a->A[i]);
    }
    }
}

int pesquisarCodigo(repositorio *a,int e){
    for(int i=a->ini;i<a->fim;i++){
        if(a->D[i]==e){
            return i;
        }
    }
    return -1;

}

int pesquisarValor(repositorio *a,int e){
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

void esvaziar(repositorio *a){
    for(int i=a->ini;i<a->fim;i++){
        a->D[i]=0;
        a->A[i]=0;
    }
    a->fim=a->ini;
    printf("Lista vazia!\n");
}
