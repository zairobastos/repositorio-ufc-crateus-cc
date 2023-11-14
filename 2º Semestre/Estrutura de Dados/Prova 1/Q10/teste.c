#include <stdio.h>
#include <stdlib.h>
#include "teste.h"
#define MAXTAM 1000

struct elemento{
int valor;
};

struct pilha{
Elemento Item[MAXTAM];
int topo;
};

Pilha* pilha_createe(){
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
        printf("Erro: Sem espaço na pilha\n");
    }
    else{
        pilha->Item[pilha->topo] = *n;
        pilha->topo ++;
    }
}

void desempilha (Pilha * pilha){
    Pilha *aux = pilha_createe();
    if(vazia(pilha)){
        printf("Erro: pilha vazia\n");
    }
    else{
        *aux->Item = pilha->Item[pilha->topo-1];
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


void teste_pilha(Pilha *pilha,int e){
    if(e%2 == 0){
        Elemento * item = inicializaElemento(e);
        empilha(item,pilha);
        printf("Valor empilhado.\n");
    }
    else{
        desempilha(pilha);
        printf("Pilha desempilhado um valor.\n");

    }
}

void mostra(Pilha * pilha){
    if(vazia(pilha)){
        printf("Erro: pilha vazia.");
    }
    else{
        while(tamanho(pilha) != 0){
            desempilha(pilha);
            printf("Pilha desempilhado um valor.\n");
            imprime(pilha);
        }
    }
}
