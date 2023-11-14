#include <stdio.h>
#include <stdlib.h>
#include "teste.h"


int main(){

   Pilha* pi = pilha_createe();

   int a,b,cont,aux;

   do{
    printf("Digite o valor a ser inserido:");
    scanf("%d",&a);

    teste_pilha(pi,a);
    cont ++;
   }while(cont != 10);

   aux=tamanho(pi);
   printf("O tamanho da pilha e:%d\n",aux);
   imprime(pi);
   mostra(pi);
   free(pi);

}
