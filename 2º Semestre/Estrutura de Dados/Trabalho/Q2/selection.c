#include <stdio.h>
#include <stdlib.h>
#include "selection.h"

vetor * create(int n){

    vetor *v = (vetor*) malloc(sizeof(vetor));

    if(v != NULL){
        v->tam = n;
        v->n = 0;
        v->vet = (produto*) malloc(sizeof(produto)*n);
    }

    return v;
}

void add(vetor *v, int codigo,float valor){
    produto *p = (produto*) malloc(sizeof(produto));

    if(p != NULL){
        p->codigo = codigo;
        p->valor = valor;
    }

    if(v->n <= v->tam){
        v->vet[v->n] = p;
        v->n ++;
    }
    else{
        printf("Erro: vetor cheio!");
    }

    printf("Valor adicionado com sucesso!\n");
}

void selectionSort(vetor *v){

    int salvar = 0,aux;

    for(int i=0; i<v->n;i++){
            salvar = i;
        for(int j=i+1;j<v->n;j++){
            if(v->vet[j]->codigo < v->vet[salvar]->codigo){
                salvar = j;
            }
            aux = v->vet[salvar];
            v->vet[salvar] = v->vet[i];
            v->vet[i] = aux;
        }
    }

}


void imprime (vetor * v){
    printf("\nOs produtos sao:\n");
    for(int i=0;i<v->n;i++){
        printf("Codigo: %d, Valor: %.2f \n",v->vet[i]->codigo,v->vet[i]->valor);
    }
}
