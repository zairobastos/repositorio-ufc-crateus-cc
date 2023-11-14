#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

Vetor* create(int n){
	 
	Vetor *v = (Vetor *)malloc(sizeof(Vetor));
		 
	if (v != NULL) {
		v->n = n;
		v->contador = 0;
		v->dados = (Produto*) malloc(sizeof(Produto)*n);
	}
	
	return v;
}

void insertionSort(Vetor* v) {
	
	printf("\n*******ORDENANDO VETOR***********\n");
	
	int i, j;  
	
	Produto *p;
	
    for (i = 1; i < v->contador; i++) 
    {  
        p = v->dados[i];  
        j = i - 1;  
  
        
        while (j >= 0 && v->dados[j]->codigo > p->codigo) 
        {  
            v->dados[j + 1] = v->dados[j];  
            j = j - 1;  
        }  
        
        v->dados[j + 1] = p;  
    }  
	
}  

int* add(Vetor* v, int codigo, float valor){
	
	Produto *p = createProduto(codigo, valor);
	
	if(p != NULL && v != NULL && v->contador < v->n){
		v->dados[v->contador++] = p;
		return 1; 
	}else
		return 0;
	
}

void printVetor(Vetor* v){
	printf("\n*******IMPRIMINDO VETOR***********\n");
	int i = 0;
	for(i = 0; i < v->contador; i++)
		printf("vetor[%i] = <codigo: %i, valor: %.2f> \n", i, v->dados[i]->codigo,v->dados[i]->valor);
}

Produto* createProduto(int codigo, float valor){
	
	Produto *p = (Produto *)malloc(sizeof(Produto));
	
	if(p!=NULL){
		p->codigo = codigo;
		p->valor = valor;
	}
	
	return p;
	
}
