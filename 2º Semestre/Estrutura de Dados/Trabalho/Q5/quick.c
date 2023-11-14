#include <stdio.h>
#include <stdlib.h>
#include "quick.h"

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

void quickSort(vetor *v,int n,int k){

    int i, j;

        produto *x = (produto *)malloc(sizeof(produto));
        produto *y = (produto *)malloc(sizeof(produto));

        i = n;
        j = k;
        x = v->vet[(n + k) / 2];

        while(i <= j){
            while(v->vet[i]->codigo < x->codigo && i < k){
                i++;
            }
            while(v->vet[j]->codigo > x->codigo && j > n){
                j--;
            }
            if(i <= j){
                y = v->vet[i];
                v->vet[i] = v->vet[j];
                v->vet[j] = y;
                i++;
                j--;
            }
        }

        if(j > n){
            quickSort(v, n, j);
        }
        if(i < k){
            quickSort(v, i, k);
        }

}


void imprime (vetor * v){
    printf("\nOs produtos sao:\n");
    for(int i=0;i<v->n;i++){
        printf("Codigo: %d, Valor: %.2f \n",v->vet[i]->codigo,v->vet[i]->valor);
    }
}
