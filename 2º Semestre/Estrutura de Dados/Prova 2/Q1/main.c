#include <stdio.h>
#include <stdlib.h>
#include "arvore.h"

int main(){

    arvoreBI * a = create();

	printf("%d\n",isEmpty(a));

    createRoot(a,10);

    add(a,a->raiz,9);
    add(a,a->raiz,8);
    add(a,a->raiz,11);
    add(a,a->raiz,12);
    add(a,a->raiz,7);
    add(a,a->raiz,13);

    printf("%d\n\n",isEmpty(a));

    printf("O tamanho e:%d\n\n",size(a));

    find(a,12);

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
