#include <stdio.h>
#include <stdlib.h>
#include "insertion.h"

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

void insertionSort(vetor *v){

    produto * chave = (produto*) malloc(sizeof(produto));

    int i,j;

    for(i = 1; i < v->n; i++){
		chave = v->vet[i];
		for(j = i-1; j >= 0 && chave->codigo < v->vet[j]->codigo; j--){
			v->vet[j+1] = v->vet[j];
		}
		v->vet[j+1] = chave;
	}

}


void imprime (vetor * v){
    printf("\nOs produtos sao:\n");
    for(int i=0;i<v->n;i++){
        printf("Codigo: %d, Valor: %.2f \n",v->vet[i]->codigo,v->vet[i]->valor);
    }
}
