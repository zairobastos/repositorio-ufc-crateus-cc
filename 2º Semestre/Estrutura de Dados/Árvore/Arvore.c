#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>
#include "Arvore.h"
	
	ArvoreBinaria *criar() {
		 ArvoreBinaria *arv = (ArvoreBinaria *)malloc(sizeof(ArvoreBinaria));
		 if (arv != NULL) {
			arv->raiz = NULL;
		 }
		 return arv;
	}
	
	//criar raiz (root)
	No *criarRaiz(ArvoreBinaria *arvore, int valor) {
		 arvore->raiz = (No *) malloc(sizeof (No));
		 if (arvore->raiz != NULL) {
			 arvore->raiz->filhoEsquerda = NULL;
			 arvore->raiz->filhoDireita = NULL;
			 arvore->raiz->valor = valor;
		 }
		 return arvore->raiz;
	}

	 No *inserir_filho(int lado, No *v, int w) {
		 No *v_f = (No *) malloc(sizeof (No)); 

		 if (v_f != NULL) {
			 v_f->filhoDireita = NULL;
			 v_f->filhoEsquerda = NULL;
			 v_f->valor = w;

			 if (lado == LADO_ESQ) {
				v->filhoEsquerda = v_f;
			 } else {
				v->filhoDireita = v_f;
			 }
		 }

		 return v_f;
	 }
	 
	 void pre_ordem_aux(No *raiz) {
		if (raiz != NULL) {
			printf("%i", raiz->valor);
			pre_ordem_aux(raiz->filhoEsquerda);
			pre_ordem_aux(raiz->filhoDireita);
		}
	}
	
	void pre_ordem(ArvoreBinaria *arvore) {
		pre_ordem_aux(arvore->raiz);
	}

	void em_ordem_aux(No *raiz) {
		if (raiz != NULL) {
			em_ordem_aux(raiz->filhoEsquerda);
			printf("%i", raiz->valor);
			em_ordem_aux(raiz->filhoDireita);
		}
	}
	
	void em_ordem(ArvoreBinaria *arvore) {
		em_ordem_aux(arvore->raiz);
	}
	
	void pos_ordem_aux(No *raiz) {
		if (raiz != NULL) {
			pos_ordem_aux(raiz->filhoEsquerda);
			pos_ordem_aux(raiz->filhoDireita);
			printf("%i", raiz->valor);
		}
	}

	void pos_ordem(ArvoreBinaria *arvore) {
		pos_ordem_aux(arvore->raiz);
	}
 
