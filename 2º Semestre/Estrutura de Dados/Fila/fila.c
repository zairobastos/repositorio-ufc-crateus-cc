#include <stdio.h>
#include <stdlib.h>
#include "fila.h"


struct fila{
	int limite;
	int contador; //conta o numero de insercoes na pilha, i. e., a quantidade de elementos presente na mesma
	int* dados; //ponteiro que irá apontar para o vetor alocado dinamicamente para receber os dados da pilha
};

Fila* create(int n){
	
		Fila* fi = (Fila*) malloc(sizeof(Fila));
	
		//condição para caso o malloc não conseguir alocar memória para criar a pilha
		if(fi == NULL){
			return NULL;
		}else{
			fi->dados = (int*) malloc(n * sizeof(int));
			fi->limite = n;
			fi->contador = 0;
			return fi;
		}
			
}

int add(Fila* fi, int e){
	
	if(fi!=NULL && fi->contador < fi->limite ) {
		int posicaoDaInsercao = fi->contador;
		fi->dados[posicaoDaInsercao] = e;
		fi->contador++;
		return 1;
	}
	else
		return 0;
		
}

int pop(Fila* fi){
	
	if(fi!=NULL && !isEmpty(fi) ){
		
		int i = 0;
		
		int k = 0;
		
		int * novoVetor = (int*) malloc(fi->limite * sizeof(int));
				
		for(i = 1; i < fi->contador; i++){
			
			novoVetor[k] = fi->dados[i];
			k++;
					
		}
		
		fi->contador--;
		free(fi->dados);
		fi->dados = novoVetor;
				
		return 1;
			
	}else 
		return 0;
	
	return 0;
	
}

int last(Fila* fi){
	
	//Vai retornar o prato, ops, o número inteiro situado no topo do vetor 'dados' da pilha pi
	//Ou seja, vai retorna o último inteiro inserido
	if(fi!=NULL && !isEmpty(fi)){
		int posicaoDoUltimoInserido = fi->contador-1;
		return fi->dados[posicaoDoUltimoInserido];
	}else
		return -1;
	
}

int first(Fila* fi){

	if(fi!=NULL && !isEmpty(fi)){
		//BOTTOM = fundo ou base da pilha, i. e., o primeiro elemento inserido
		return fi->dados[0];
	}else
		return -1;

}

//A pilha está vazia? retorna 1, se sim, e 0 para o caso oposto.
int isEmpty(Fila* fi){
	
	
	//avalia se pi aponta para uma pilha dinamicamente alocada
	if(fi == NULL){
		return 0;
	}
	
	if(fi->contador <= 0) //<= 0 para prever qualquer bug. Coisa de programador que não quer ser incomodado sexta a noite ou durante o fds.
		return 1;
	else
		return 0;
		
	//AO INVÉS DE IF-ELSE, PODERIAMOS TER APENAS UMA ÚNICA LINHA DE CÓDIGO:
	//return pi != NULL && pi->contador > 0;
	
}

int isFull(Fila* fi){
	
	
	//avalia se pi aponta para uma pilha dinamicamente alocada
	if(fi == NULL){
		return 0;
	}
	
	if(fi->contador >= fi->limite) //<= 0 para prever qualquer bug. Coisa de programador que não quer ser incomodado sexta a noite ou durante o fds.
		return 1;
	else
		return 0;
		
	//AO INVÉS DE IF-ELSE, PODERIAMOS TER APENAS UMA ÚNICA LINHA DE CÓDIGO:
	//return pi != NULL && pi->contador > 0;
	
}

void printAll(Fila* fi){
	int i = 0;
	
	for(i=0; i < fi->contador; i++)
		printf("fi->dados[%i] = %i \n", i, fi->dados[i]);
	
}
