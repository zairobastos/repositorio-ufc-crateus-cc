 #include <stdio.h>
#include <stdlib.h>
#include "ListaCircular.h"

ListaCircular *create() {
	 ListaCircular *lista = (ListaCircular *)malloc(sizeof (ListaCircular));

	 if(lista != NULL) {
		 lista->inicio = NULL;
		 lista->fim = NULL;
		 lista->tamanho = 0;
	 }

	 return lista;
}

