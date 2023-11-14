#include <stdio.h>
#include <stdlib.h>
#include "No.h"
 
 
	struct no{
		int valor;
		struct no *anterior;
		struct no *proximo;
	 } ;

	typedef struct no No; 

	typedef struct {
		 No *inicio;
		 No *fim;
		 int tamanho;
	} ListaDuplamenteEncadeada;

ListaCircular* create();

int add(ListaCircular* lista, int valor);

int pop(ListaCircular *lista, int chave);

int isEmpty(ListaCircular* lista);

void printListaEncadeada(ListaCircular* lista);


	void printAll (ListaCircular* l) {
		No* p = l->inicio;
		/* faz p apontar para o nó inicial */
		/* testa se lista não é vazia */
		if (p != NULL)  {
		/* percorre os elementos até alcançar novamente o início */
			do {
				printf("%d\n", p->valor);     /* imprime informação do nó */
				p = p->prox; /* avança para o próximo nó */
			} while (p != l->inicio);
		}	
	}
	
	