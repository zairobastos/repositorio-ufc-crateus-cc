#include <stdio.h>
#include <stdlib.h>
#include "encadeiada.h"

int main(){

    int d,aux;

    lista *a = create();

    printf("ATENCAO O RETORNO DAS OPERACOES 0-VERDADEIRO E -1-FALSO\n");
    system("pause");

    do{

        printf("\n----------Menu-----------\n");
        printf("1-Adicionar um valor\n");
        printf("2-Remover valor\n");
        printf("3-Quantidade de elementos na lista\n");
        printf("4-Verificar a posicao do elemento na lista\n");
        printf("5-Verificar se a lista esta vazia\n");
        printf("6-Limpar todos os elementos da lista\n");
        printf("7-Imprimir valores\n");
        printf("0-Para sair do programa\n");
        scanf("%d",&aux);

        switch(aux){
            case 1:
                printf("Digite o valor a ser adicionado:");
                scanf("%d",&d);
                elemento *c = createElemento(d);
                printf("%d\n",add(a,c));
                break;

            case 2:
                printf("%d\n",remover(a));
                break;

            case 3:
                printf("O tamanho da fila e %d\n",size(a));
                break;

            case 4:
                printf("Digite o valor a ser elemento a ser pesquisado:");
                scanf("%d",&d);
                elemento *g = createElemento(d);
                printf("A posicao do elemento e %d\n",find(a,g));
                break;

            case 5:
                printf("%d\n",isEmpty(a));
                break;

            case 6:
                printf("%d\n",clear(a));
                break;

            case 7:
                imprime(a);
                break;
        }

    }while(aux != 0);

    free(a);
}
