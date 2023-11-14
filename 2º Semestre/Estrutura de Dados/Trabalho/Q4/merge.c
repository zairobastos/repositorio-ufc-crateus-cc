#include <stdio.h>
#include <stdlib.h>
#include "merge.h"

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

void mergeSort(vetor *v,int esquerda,int direita){

    if(esquerda >= direita){
		return;
	}

	int  meio= esquerda+(direita-esquerda)/2;
	mergeSort(v, esquerda, meio);
	mergeSort(v, meio+1, direita);
	merge(v, esquerda, meio, direita);

}

void merge(vetor* v, int esquerda, int meio, int direita){

	int num1 = meio-esquerda+1;
	int num2 = direita-meio;

	int i, j;

	vetor* S= create(num1);
	vetor* T= create(num2);

	for(i = 0; i < num1; i++){
		S->vet[i] = v->vet[esquerda + i];
	}
	for(j = 0; j < num2; j++){
		T->vet[j] = v->vet[meio + 1 + j];
	}

	i = 0;
	j = 0;
	int k = esquerda;

	while(i < num1 && j <num2){
		if(S->vet[i]->codigo <= T->vet[j]->codigo){
			v->vet[k] = S->vet[i];
			i++;
		}
		else{
			v->vet[k] = T->vet[j];
			j++;
		}
		k++;
	}

	while(i < num1){
		v->vet[k] = S->vet[i];
		i++;
		k++;
	}

	while(j < num2){
		v->vet[k] = T->vet[j];
		j++;
		k++;
	}
}


void imprime (vetor * v){
    printf("\nOs produtos sao:\n");
    for(int i=0;i<v->n;i++){
        printf("Codigo: %d, Valor: %.2f \n",v->vet[i]->codigo,v->vet[i]->valor);
    }
}
