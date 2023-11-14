#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

ListaEncadeada *create() {
	 ListaEncadeada *lista = (ListaEncadeada *)malloc(sizeof (ListaEncadeada));

	 if(lista != NULL) {
		 lista->inicio = NULL;
		 lista->fim = NULL;
		 lista->tamanho = 0;
	 }

	 return lista;
}


int add(ListaEncadeada *lista, int valor) {
	 
	No* pnovo = (No*) malloc(sizeof(No));

	if(pnovo != NULL) {
			 pnovo->valor = valor;
			 pnovo->proximo = NULL;

			 if(lista->inicio == NULL) {
				lista->inicio = pnovo;
			 } else {
				lista->fim->proximo = pnovo;
			 }

			 lista->fim = pnovo;
			 lista->tamanho++;
			 return 1;
	 }
	 
	 return 0;
}

int pop(ListaEncadeada *lista, int chave){
	
	 if (!isEmpty(lista)) {
		 
		 No *alvo = lista->inicio;
		 No *anterior;
		 
		 while(alvo != NULL && alvo->valor != chave) {
			anterior = alvo;
			alvo = alvo->proximo;
		 }

		 if(alvo != NULL) {
			 if(alvo != lista->inicio) {
				anterior->proximo = alvo->proximo;
			 } else {
				lista->inicio = alvo->proximo;
			 }

			 if(alvo == lista->fim) {
				lista->fim = anterior;
			 }

			 lista->tamanho--;
			 freeNo(alvo);
			 return 1;
			 
		 }
	 }
	 return 0;
}

int isEmpty(ListaEncadeada* lista){
	return lista->tamanho <= 0;
}

void printListaEncadeada(ListaEncadeada* lista){
		 
		 printf("\n----------IMPRIMINDO LISTA -------------\n\n");
		 
		 printf("Lista [tamanho: %i, limite: quantidade de memo'ria aloca'vel] \n\n", lista->tamanho);
		 
		 if(isEmpty(lista))
		 	printf("Lista esta' vazia.\n");
		 else{
		 	No *alvo = lista->inicio;
		 
			 while(alvo != NULL){
			 	printNo(alvo);
				alvo = alvo->proximo;
			 }	
		 }
		
}
