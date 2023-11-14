#include <stdio.h>
#include <stdlib.h>
#include "concatena.h"

int main(){

    int a,b,cont,aux;

    Fila *wa = inicializaFila();
    Fila *wb = inicializaFila();
    definir(wa);

    do{
        printf("Digite o valor a ser inserido na primeira fila:");
        scanf("%d",&a);

        printf("%d\n",inserir(wa,a));

        printf("Quer digitar outro valor para a primeira fila?\n");
        printf("1-Sim\n");
        printf("2-Nao\n");
        scanf("%d",&b);
        cont ++;
        if(cont ==1000){
            printf("Fila cheia");
            break;
        }
       }while(b != 2);
       b==0;
    do{
        printf("Digite o valor a ser inserido na segunda fila:");
        scanf("%d",&a);

        printf("%d\n",inserir(wb,a));

        printf("Quer digitar outro valor para a segunda fila?\n");
        printf("1-Sim\n");
        printf("2-Nao\n");
        scanf("%d",&b);
        cont ++;
        if(cont ==1000){
            printf("Fila cheia");
            break;
        }
       }while(b != 2);

    imprime1(wa);
    imprime2(wb);
    concate(wa,wb);
    imprime3(wa);
    imprime2(wb);
    free(wa);
    free(wb);
}
