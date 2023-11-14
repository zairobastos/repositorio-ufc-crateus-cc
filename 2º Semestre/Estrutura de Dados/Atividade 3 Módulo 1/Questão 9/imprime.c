#include <stdio.h>
#include <stdlib.h>
#include "imprime.h"
#define MAXTAM 1000

struct fila{
    int A[MAXTAM];
    int ini,fim;
};

Fila * inicializaFila(){
    Fila * w = (Fila*) malloc(sizeof(Fila));
    return w;
}

void definir(Fila * w){
    w->ini = 0;
    w->fim = 0;
}

int vazia(Fila * w){
    if(w->ini == w->fim){
        return 1;
    }
    else{
        return 0;
    }
}

int cheia(Fila * w){
    if(w->ini == ((w->fim+1)%MAXTAM)){
        return 1;
    }
    else{
        return 0;
    }
}

int inserir(Fila * w,int item){
    if(cheia(w)==1){
        return 0;
    }
    else{
        w->fim = ((w->fim+1)%MAXTAM);
        w->A[w->fim] = item;
        return 1;
    }
}

int remover(Fila * w,int * item){
    if(vazia(w) == 1){
        return 0;
    }
    else{
        w->ini = ((w->ini+1)%MAXTAM);
        *item = w->A[w->ini];
        return 1;
    }
}

int tamanho(Fila * w){
    if(w->ini <= w->fim){
        return(w->fim - w->ini);
    }
    else{
        return(MAXTAM-(w->fim - w->ini));
    }
}

int comeco_fi(Fila * w,int * item){
    if(vazia(w)){
        return 0;
    }
    else{
        item = w->A[(w->ini + 1)% MAXTAM];
        return 1;
    }
}

void imprime(Fila *w){
    if(vazia(w)){
        printf("Erro: Fila vazia");
    }
    for(int i=0;i<tamanho(w);i++){
        printf("O valor impresso e:%d\n",w->A[((w->ini +1)%MAXTAM)+i]);
    }
}
