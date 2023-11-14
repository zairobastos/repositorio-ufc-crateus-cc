#include <stdio.h>
#include <stdlib.h>
#include "ListaEstatica.h"


struct listaEstatica{
	int limite;
	int contador; 
	int* dados; 
	int* insercoes;
};

int addAtPosition(ListaEstatica* ed, int e, int pos){
	
	if(ed!=NULL && ed->contador < ed->limite && pos >= 0 && pos <  ed->limite && ed->insercoes[pos] != 1) {
		
			ed->dados[pos] = e;
		
			ed->contador++;
		
			return 1;	
			
	}
	else
		return 0;
	
}
