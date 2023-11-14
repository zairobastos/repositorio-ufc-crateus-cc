#include <stdio.h>
#include <stdlib.h>
#include "concatena.h"
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

void imprime1(Fila *w){
    if(vazia(w)){
        printf("Erro: Fila vazia");
    }
    for(int i=0;i<tamanho(w);i++){
        printf("O valor impresso da primeira fila e:%d\n",w->A[((w->ini +1)%MAXTAM)+i]);
    }
}

void imprime2(Fila *w){
    if(vazia(w)){
        printf("Erro: Fila vazia");
    }
    for(int i=0;i<tamanho(w);i++){
        printf("O valor impresso da segunda fila e:%d\n",w->A[((w->ini +1)%MAXTAM)+i]);
    }
}

void imprime3(Fila *w){
    if(vazia(w)){
        printf("Erro: Fila vazia");
    }
    for(int i=0;i<tamanho(w);i++){
        printf("O valor impresso da fila concatenada e:%d\n",w->A[((w->ini +1)%MAXTAM)+i]);
    }
}

void concate(Fila *w1,Fila *w2){
    if(vazia(w1) || vazia(w2)){
        printf("Erro: Fila vazia");
    }
    else{
        for(int i=0;i<tamanho(w2);i++){
        inserir(w1,w2->A[((w2->ini +1)%MAXTAM)+i]);
        w2->A[((w2->ini + 1)%MAXTAM)+i]=NULL;
        }
    }
}
