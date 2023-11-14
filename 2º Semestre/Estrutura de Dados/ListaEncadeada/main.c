#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeada.h"

int main(int argc, char *argv[]) {
	
	ListaEncadeada * lista = create();
	
	printListaEncadeada(lista);
	
	add(lista, 10);
	
	printListaEncadeada(lista);

	add(lista, 5);
	
	printListaEncadeada(lista);
	
	add(lista, 15);

	add(lista, 25);

	add(lista, 50);
	
	printListaEncadeada(lista);
	
	pop(lista, 10);

	printListaEncadeada(lista);
	
	pop(lista, 25);
	
	printListaEncadeada(lista);
	
	pop(lista, 5);
	
	printListaEncadeada(lista);
	
	return 0;
}
