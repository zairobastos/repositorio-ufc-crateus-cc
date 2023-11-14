#include <stdio.h>
#include <stdlib.h>
#include "inverte.h"
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

void empilha (Elemento *n,Pilha * pilha){
    if(pilha->topo == MAXTAM){
        printf("Erro: Sem espaço na pilha");
    }
    else{
        pilha->Item[pilha->topo] = *n;
        pilha->topo ++;
    }
}

void desempilha (Pilha * pilha,Elemento * item){
    if(vazia(pilha)){
        printf("Erro: pilha vazia");
    }
    else{
        *item = pilha->Item[pilha->topo-1];
        pilha->topo -- ;
    }
}

int tamanho(Pilha * pilha){
    return (pilha->topo);
}


void imprime(Pilha* pilha){
    int i;

    for(i=0;i<pilha->topo;i++){
        printf("Impresso:%d\n",pilha->Item[i].valor);
    }
}

void inverte(Pilha* pilha){
    Pilha *aux = (Pilha*) malloc (sizeof (Pilha));
    //aux->topo = 0;
    while(pilha->topo != 0){
        aux->Item[aux->topo].valor = pilha->Item[pilha->topo-1].valor;
        aux->topo ++ ;
        pilha->topo --;
    }
    int i;

    for(i=0;i<aux->topo;i++){
        printf("invertido:%d\n",aux->Item[i].valor);
    }
}
