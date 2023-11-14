#include <stdio.h>
#include <stdlib.h>
#include "No.h"
 
typedef struct {
	 No *inicio;
	 No *fim;
	 int tamanho;
} ListaEncadeada;

ListaEncadeada* create();

int add(ListaEncadeada* lista, int valor);

int pop(ListaEncadeada *lista, int chave);

int isEmpty(ListaEncadeada* lista);

void printListaEncadeada(ListaEncadeada* listaEncadeada);
