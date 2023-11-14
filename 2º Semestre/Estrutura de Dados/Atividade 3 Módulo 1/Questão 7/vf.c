#include <stdio.h>
#include <stdlib.h>
#include "vf.h"
#define MAXTAM 1000

struct elemento{
int valor;
};

struct pilha{
Elemento Item[MAXTAM];
int topo;
};

Pilha*inicilizaPilha(){
    Pilha *pilha = (Pilha*) malloc (sizeof (Pilha));
    return pilha;
}
Elemento * inicializaElemento(int n){
    Elemento* item=(Elemento*)malloc (sizeof(Elemento));
    item->valor = n;
    return item;
}

void FPVazia(Pilha * pilha){
    pilha->topo = 0;
}

int vazia(Pilha * pilha){
    return(pilha->topo == 0);
}

void verificav(Pilha *pilha){
    if(pilha->topo == 0){
        printf("True\n");
    }
    else{
        printf("False\n");
    }
}

void empilha (Elemento *n,Pilha * pilha){
    if(pilha->topo == MAXTAM){
        printf("Erro: Sem espaço na pilha");
    }
    else{
        pilha->Item[pilha->topo] = *n;
        pilha->topo ++;
    }
}

