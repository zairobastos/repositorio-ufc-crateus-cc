#include <stdio.h>
#include <stdlib.h>
#include "repositorio.h"

int main(){

   int d,e,n,aux;

    printf("Digite o tamanho do repositorio:");
    scanf("%d",&n);

    repositorio *q = inicializaLista();

    create(q,n);
    ini(q);

    printf("ATENCAO O RETORNO DAS OPERACOES 0-VERDADEIRO E -1-FALSO\n");
    system("pause");

    do{

        printf("----------Menu-----------\n");
        printf("1-Adicionar um valor\n");
        printf("2-Quantidade de elementos na lista\n");
        printf("3-Verificar a posicao do codigo\n");
        printf("4-Verificar o valor\n");
        printf("5-Verificar se o repositorio esta cheio\n");
        printf("6-Verificar se o repositorio esta vazia\n");
        printf("7-Limpar todos os elementos da lista\n");
        printf("8-Imprimir valores\n");
        printf("9-Tratar\n");
        printf("0-Para sair do programa\n");
        scanf("%d",&aux);
        printf("\n");

        switch(aux){
            case 1:
                printf("Digite o codigo a ser adicionado:");
                scanf("%d",&d);
                printf("Digite o valor a ser adicionado:");
                scanf("%d",&e);
                printf("%d\n",add(q,d,e));
                break;

            case 2:
                printf("O tamanho do repositorio e %d\n",tamanho(q));
                break;

            case 3:
                printf("Digite a posicao do elemento a ser pesquisado:");
                scanf("%d",&d);
                printf("A posicao do elemento e %d\n",pesquisarCodigo(q,d));
                break;

            case 4:
                printf("Digite o valor a ser elemento a ser pesquisado:");
                scanf("%d",&d);
                printf("A posicao do elemento e %d\n",pesquisarValor(q,d));
                break;

            case 5:
                printf("%d",estaCheio(q));
                break;

            case 6:
                printf("%d",estaVazio(q));
                break;

            case 7:
                esvaziar(q);
                break;

            case 8:
                imprime(q);
                break;

            case 9:
                printf("%d\n",tratar(q));
                break;
        }

    }while(aux != 0);

    free(q);

}
