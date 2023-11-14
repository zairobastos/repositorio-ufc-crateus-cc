
#include <stdio.h>
#include <stdlib.h>
#include "Bag.h"

Bag* create(int n){
	
	Bag * p = (Bag*) malloc(sizeof(Bag));
 	
 	p->n = n;
 	p->k = 0;
 	
 	p->repositorio = (Pedido**) malloc(sizeof(Pedido*) * n);
	 	
 	return p;
	
}

int add(Bag* bag, Pedido* p){
	
	if(bag!=NULL && bag->k < bag->n){
	
		bag->repositorio[bag->k] = p; //poderiamos ter [k++]
		bag->k++;
		
		return 1;
		
	}else
		return 0;
	
}

Pedido* get(Bag* bag){
	
	if(bag != NULL && bag->k > 0){
		
		//COMEÇO: BLOCO DE SELEÇÃO DO PEDIDO
		int posicao = rand() % bag->k; //gera valores aleatórios entre 0 e k
		
		Pedido* pedido = bag->repositorio[posicao]; //assim, seleciona um valor aletório da bag
		
		bag->repositorio[posicao] = NULL;
		
		//FIM: BLOCO DE SELEÇÃO DO PEDIDO
		
		//COMEÇO: BLOCO DE REMANEJO DO REPOSITÓRIO
		int i = 0;
		
		int j = 0;
		
		Pedido ** novoVetor = (int*) malloc(bag->n * sizeof(Pedido*));
		
		for(i = 0; i < bag->k; i++){
			
			if(i != posicao){
				novoVetor[j] = bag->repositorio[i];
				j++;
			}
			
					
		}
		
		bag->k--;
		free(bag->repositorio);
		bag->repositorio = novoVetor;
		
		//FIM: BLOCO DE REMANEJO DO REPOSITÓRIO
				
		return pedido;
		
		
	}else
		return NULL;
	
}

void printBag(Bag* bag){
	
	if(bag != NULL && bag->k > 0){
		
		printf("\n!! Printando bag !!\n");
		
		int i = 0;
		
		for(i = 0; i < bag->k; i++){
			if(bag->repositorio[i]!=NULL){
				Pedido *p = bag->repositorio[i];
				printPedido(p);
			}
		}
		
	}else
	 printf("!! Bag va'zio !!\n");
	
}
