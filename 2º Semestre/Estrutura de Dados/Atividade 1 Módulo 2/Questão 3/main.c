#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

int main(){

    int d,n,aux;

    printf("Digite o tamanho da lista:");
    scanf("%d",&n);

    lista *q = inicializaLista();

    create(q,n);
    ini(q);

    printf("ATENCAO O RETORNO DAS OPERACOES 0-VERDADEIRO E -1-FALSO\n");
    system("pause");

    do{

        printf("----------Menu-----------\n");
        printf("1-Adicionar um valor\n");
        printf("2-Remover valor\n");
        printf("3-Quantidade de elementos na lista\n");
        printf("4-Verificar a posicao no vetor por busca sequencial\n");
        printf("5-Verificar a posicao no vetor por busca binaria\n");
        printf("6-verificar se a lista esta cheia\n");
        printf("7-Verificar se a lista esta vazia\n");
        printf("8-Limpar todos os elementos da lista\n");
        printf("9-Imprimir valores\n");
        printf("0-Para sair do programa\n");
        scanf("%d",&aux);

        switch(aux){
            case 1:
                printf("Digite o valor a ser adicionado:");
                scanf("%d",&d);
                printf("%d\n",add(q,d));
                break;

            case 2:
                printf("Digite o valor a ser removido:");
                scanf("%d",&d);
                printf("%d\n",remover(q,d));
                break;

            case 3:
                printf("O tamanho da fila e %d\n",size(q));
                break;

            case 4:
                printf("Digite o valor a ser elemento a ser pesquisado busca sequencial:");
                scanf("%d",&d);
                printf("A posicao do elemento e %d\n",linearSearch(q,d));
                break;

            case 5:
                printf("Digite o valor a ser elemento a ser pesquisado busca binaria:");
                scanf("%d",&d);
                printf("A posicao do elemento e %d\n",bynarySearch(q,d));
                break;

            case 6:
                printf("%d",isFull(q));
                break;

            case 7:
                printf("%d",isEmpty(q));
                break;

            case 8:
                clear(q);
                break;

            case 9:
                imprime(q);
                break;
        }

    }while(aux != 0);

    free(q);
}
