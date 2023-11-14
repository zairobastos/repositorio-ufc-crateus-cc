#include <stdio.h>
#include <stdlib.h>
#include "imprime.h"struct fila"
#define MAXTAM 1000

struct fila{
    int A[MAXTAM];
    int ini,fim;
};

Fila * fila_create(){
    Fila * w = (Fila*) malloc(sizeof(Fila));
    return w;
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

int fila_insert(Fila * w,int item){
    if(cheia(w)==1){
        return 0;
    }
    else{
        w->fim = ((w->fim+1)%MAXTAM);
        w->A[w->fim] = item;
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


void print_rec(Fila *w,int i){
        printf("O valor impresso e:%d\n",w->A[((w->ini +1)%MAXTAM)+i]);
        i++;
        if(i != tamanho(w)){
        print_rec(w,i);
        }
}
