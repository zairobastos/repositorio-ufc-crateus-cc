#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	ArvoreBinaria *av = criar();
	
	criarRaiz(av, 5);

	inserir_filho(LADO_ESQ, av->raiz, 2);
	
	inserir_filho(LADO_DIR, av->raiz->filhoEsquerda, 8);

	inserir_filho(LADO_ESQ, av->raiz->filhoEsquerda, 1);

	inserir_filho(LADO_DIR, av->raiz, 10);

	inserir_filho(LADO_DIR, av->raiz->filhoDireita, 15);

	inserir_filho(LADO_ESQ, av->raiz->filhoDireita, 12);
	
	em_ordem(av);
	
	return 0; 
}
