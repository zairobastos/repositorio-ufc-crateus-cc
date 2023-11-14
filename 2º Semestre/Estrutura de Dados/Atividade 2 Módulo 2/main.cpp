#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char* argv[]) {
	
	arvoreBI * a = create();
	
	printf("%d\n",isEmpty(a));
		
    createRoot(a,'a');

    add(a,L_ESQUERDO,a->raiz,'b');
    add(a,L_DIREITO,a->raiz,'c');
    add(a,L_ESQUERDO,a->raiz->filhoEsquerda,'d');
    add(a,L_DIREITO,a->raiz->filhoEsquerda,'e');
    add(a,L_ESQUERDO,a->raiz->filhoDireita,'f');
    add(a,L_DIREITO,a->raiz->filhoDireita,'g');
    
    printf("%d\n\n",isEmpty(a));
    
    printf("O tamanho e:%d\n\n",size(a));
    
    find(a,'c');

    printAllPre(a);
    printf("\n\n");
    printAllIn(a);
    printf("\n\n");
    printAllPost(a);
    printf("\n\n");
    
    clear(a);
    
    printf("O tamanho e:%d\n\n",size(a));
    
    printAllPre(a);
}
