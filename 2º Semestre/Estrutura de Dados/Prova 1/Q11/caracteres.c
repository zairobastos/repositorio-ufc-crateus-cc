#include <stdio.h>
#include <stdlib.h>
#include "caracteres.h"
#define MAXTAM 1000

struct fila{
    char A[MAXTAM];
    int ini,fim;
};

struct elemento{
char valor;
};

struct pilha{
Elemento Item[MAXTAM];
int topo;
};

Pilha*inicilizaPilha(){
    Pilha *pilha = (Pilha*) malloc (sizeof (Pilha));
    return pilha;
}

Elemento * inicializaElemento(char n){
    Elemento* item=(Elemento*)malloc (sizeof(Elemento));
    item->valor = n;
    return item;
}

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

int inserir(Fila * w,char item){
    if(cheia(w)==1){
        return 0;
    }
    else{
        w->fim = ((w->fim+1)%MAXTAM);
        w->A[w->fim] = item;
        return 1;
    }
}

int remover(Fila * w,char * item){
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

void imprime(Fila *w){
    if(vazia(w)){
        printf("Erro: Fila vazia");
    }
    for(int i=0;i<tamanho(w);i++){
        printf("O valor impresso e:%c\n",w->A[((w->ini +1)%MAXTAM)+i]);
    }
}

int vaziap(Pilha * pilha){
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
    if(vaziap(pilha)){
        printf("Erro: pilha vazia");
    }
    else{
        *item = pilha->Item[pilha->topo-1];
        pilha->topo -- ;
    }
}

void teste(Fila *w){
    Fila *aux= inicializaFila();
    Pilha *aux2 = inicilizaPilha();
    if(vazia(w)){
        printf("Erro: Fila vazia");
    }
    else{
        for(int i=0;i<tamanho(w);i++){
            if(w->A[(w->ini +1)%MAXTAM] >=65 && w->A[(w->ini +1)%MAXTAM] <=90){
                char a;
                aux->fim = ((aux->fim+1)%MAXTAM);
                aux->A[w->fim] = w->A[(w->ini +1)%MAXTAM];
                remover(w,a);
            }else if(w->A[(w->ini +1)%MAXTAM] >=97 && w->A[(w->ini +1)%MAXTAM] <=122){
                char a;
                aux->fim = ((aux->fim+1)%MAXTAM);
                aux->A[aux->fim] = w->A[(w->ini +1)%MAXTAM];
                remover(w,a);
            }else{
                char a;
                a = w->A[((w->ini +1)%MAXTAM)];
                empilha(a,aux2);
                remover(w,a);
            }

            while(aux->ini != aux->fim){
                char a;
                a= aux->A[((aux->ini +1)%MAXTAM)];
                inserir(w,a);
                remover(aux,a);
            }
            while(aux2->topo != 0){
                char a;
                a = aux2->Item[aux2->topo].valor;
                inserir(w,a);
                desempilha(aux2,a);
            }
            imprime(w);
        }
    }
}




