#include <stdio.h>
#include <stdlib.h>
#include "catalogo.h"

int main(){


    int d,e,f,g,n,aux;

    printf("Digite o tamanho do catalogo:");
    scanf("%d",&n);

    catalogo *q = inicializaLista();

    create(q,n);
    ini(q);

    printf("ATENCAO O RETORNO DAS OPERACOES 0-VERDADEIRO E -1-FALSO\n");
    system("pause");

    do{

        printf("----------Menu-----------\n");
        printf("1-Adicionar um ventilador\n");
        printf("2-Tamanho do catalogo\n");
        printf("3-Verificar a posicao do ventilador no catalogo\n");
        printf("4-Remover ventilador\n");
        printf("5-Verificar se o catalogo esta cheio\n");
        printf("6-Verificar se o catalogo esta vazia\n");
        printf("7-Limpar todos os elementos do catalogo\n");
        printf("8-Imprimir elementos do catalogo\n");
        printf("9-ordenar\n");
        printf("0-Para sair do programa\n");
        scanf("%d",&aux);
        printf("\n");

        switch(aux){
            case 1:
                printf("Digite o codigo do produto a ser adicionado:");
                scanf("%d",&d);
                printf("Digite a velocidade do produto em RPM:");
                scanf("%d",&e);
                printf("%d\n",adicionar(q,d,e));
                printf("Estou aqui");
                break;

            case 2:
                printf("O tamanho do catalogo e %d\n",tamanho(q));
                break;

            case 3:
                printf("Digite o codigo do produto a ser pesquisado:");
                scanf("%d",&d);
                printf("A posicao do elemento e %d\n",catalogoPes(q,d));
                break;

            case 4:
                printf("Digite o codigo do produto a ser removido:");
                scanf("%d",&d);
                printf("%d\n",removerVent(q,d));
                break;

            case 5:
               printf("%d\n",catalogoCheio(q));
                break;

            case 6:
                printf("%d\n",catalogoVazio(q));
                break;

            case 7:
                limparCatalogo(q);
                break;

            case 8:
                imprime(q);
                break;

            case 9:
                printf("%d\n",ordenar(q));
                break;

        }

    }while(aux != 0);

    free(q);
}
