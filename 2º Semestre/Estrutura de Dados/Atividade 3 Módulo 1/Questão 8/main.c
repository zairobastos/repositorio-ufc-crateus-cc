#include <stdio.h>
#include <stdlib.h>
#include "quantidade.h"

int main(){

    int a,b,cont,aux;

    Fila *wa = inicializaFila();
    do{
        printf("Digite o valor a ser inserido:");
        scanf("%d",&a);

        printf("%d\n",inserir(wa,a));

        printf("Quer digitar outro valor?\n");
        printf("1-Sim\n");
        printf("2-Nao\n");
        scanf("%d",&b);
        cont ++;
        if(cont ==1000){
            printf("Fila cheia");
            break;
        }
       }while(b != 2);

    printf("O tamanho da Fila e:%d",tamanho(wa));
    free(wa);
}
