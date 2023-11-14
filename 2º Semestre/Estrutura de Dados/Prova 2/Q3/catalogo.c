#include <stdio.h>
#include <stdlib.h>
#include "catalogo.h"

struct Catalogo{
    int *A;
    int *B;
    int ini;
    int fim;
};

int tam;

catalogo * inicializaLista(){
    catalogo * a = (catalogo*) malloc(sizeof(catalogo));
    return a;
}

void create(catalogo *a,int n){
    a->A[n];
    a->B[n];
    tam=n;
    printf("Catalogo criada com sucesso!\n");
}

void ini(catalogo *a){
    a->fim=0;
    a->ini=0;
}

int vazia(catalogo *a){
    return a->fim == a->ini;
}

int cheia(catalogo *a){
    return a->fim ==tam;
}

int catalogoCheio(catalogo *a){
    if(cheia(a)){
        return 0;
    }
    else {
        return -1;
    }
}

int catalogoVazio(catalogo *a){
    if(vazia(a)){
        return 0;
    }
    else{
        return -1;
    }
}

int tamanho(catalogo *a){
    return (a->fim-a->ini);
}

int adicionar(catalogo *a,int e,int c){
    if(cheia(a)){
        return -1;
        printf("Catalogo cheio!\n");
    }
    else{
        for(int i=a->ini;i<a->fim;i++){
            if(a->A[i] ==  e){
                return -1;
            }
        }
        a->A[a->fim] = e;
        a->B[a->fim] = c;
        a->fim ++;
        return 0;
    }
}

int removerVent(catalogo *a,int e){
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
                a->B[i]=a->B[i+1];
            }
        }
        if(cont == 1){
            a->fim --;
            return 0;
        }
    }
}

void imprime(catalogo *a){
    if(vazia(a)){
        printf("Erro: catalogo vazio.");
    }
    else{
        for(int i=a->ini;i<a->fim;i++){
        printf("Codigo:%d",a->A[i]);
        printf("Velocidade em RPM e:%d\n",a->B[i]);
    }
    }
}

int catalogoPes(catalogo *a,int e){
    for(int i=a->ini;i<a->fim;i++){
        if(a->A[i]==e){
            return i;
        }
    }
    return -1;

}

void limparCatalogo(catalogo *a){
    for(int i=a->ini;i<a->fim;i++){
        a->A[i]=0;
        a->B[i]=0;
    }
    a->fim=a->ini;
    printf("Catalogo vazia!\n");
}

int ordenar(catalogo * a){

    for(int i=a->ini;i<a->fim;i++){
        for(int j=i;j<=a->fim;j++){
            if(a->B[i] > a->B[j]){
               int aux1,aux2;
               aux1 = a->A[j];
               aux2 = a->B[j];
               a->A[j] = a->A[i];
               a->A[i] = aux1;
               a->B[j] = a->B[i];
               a->B[i] = aux2;

          }
       }
    }
    return 0;
}
