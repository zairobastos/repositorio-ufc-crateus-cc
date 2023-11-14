#include <stdio.h>
#include <stdlib.h>
#include "inverte.h"

int main(){

   Pilha* pi = inicilizaPilha();

   int a,b,cont,aux;

   FPVazia(pi);

   do{
    printf("Digite o valor a ser inserido:");
    scanf("%d",&a);

    Elemento * item = inicializaElemento(a);
    empilha(item,pi);

    printf("Quer digitar outro valor?\n");
    printf("1-Sim\n");
    printf("2-Nao\n");
    scanf("%d",&b);
    cont ++;
    if(cont ==1000){
        printf("Pilha cheia");
        break;
    }
   }while(b != 2);

  // empilha(c,pi);
   //empilha(d,pi);

   aux=tamanho(pi);
   printf("O tamanho da pilha e:%d\n",aux);
   imprime(pi);
   inverte(pi);

   free(pi);

}
