#include <stdio.h>
#include <stdlib.h>
#include "numeroComplexo.h"
#include "numeroComplexo.c"

int main(){

float x,y,aux1,aux2;

printf("Digite o valor de x para formar o numero complexo:");
scanf("%f",&x);
printf("Digite o valor de y para formar o numero complexo:");
scanf("%f",&y);

Numero* numero1 = criaNumero();
Numero* numero2 = criaNumero();

setx(numero1,x);
sety(numero1,y);

printf("O numero complexo e: %.2f+%.2fi\n",x,y);

system("pause");

//destruir1(numero1);
//destruir2(numero1);


printf("\nO numero complexo foi destruido detruido e: %.2f",x);
printf(" + %.2fi\n\n",aux2);

printf("Digite o valor de x para formar o numero complexo:");
scanf("%f",&x);
printf("Digite o valor de y para formar o numero complexo:");
scanf("%f",&y);

setx(numero1,x);
sety(numero1,y);

printf("Digite o valor de x para formar o outro numero complexo:");
scanf("%f",&x);
printf("Digite o valor de y para formar o outro numero complexo:");
scanf("%f",&y);

setx(numero2,x);
sety(numero2,y);

int somaau1 = soma1(numero1,numero2);
int somaau2 = soma2(numero1,numero2);
int subtracaoau1 = subtracao1(numero1,numero2);
int subtracaoau2 = subtracao2(numero1,numero2);

printf("\nO resultado da soma dos dois numeros complexos e:%.2f+%.2fi\n\n",somaau1,somaau2);
if(subtracaoau2 >= 0){
printf("O resultado da subtracao dos dois numeros complexos e:%.2f%.2fi\n\n",subtracaoau1,subtracaoau2);
}
else{
    subtracaoau2 = subtracaoau2 * -1;
    printf("O resultado da subtracao dos dois numeros complexos e:%.2f+%.2fi\n\n",subtracaoau1,subtracaoau2);
}

int multiplicacaoau1 = multiplicacao1(numero1,numero2);
int multiplicacaoau2 = multiplicacao2(numero1,numero2);

if(multiplicacaoau2 < 0){
printf("O resultado da multiplicacao dos dois numeros complexos e:%.2f%.2fi\n\n",multiplicacaoau1,multiplicacaoau2);
}
else{
    multiplicacaoau2 = multiplicacaoau2 * -1;
    printf("O resultado da multiplicacao dos dois numeros complexos e:%.2f+%.2fi\n\n",multiplicacaoau1,multiplicacaoau2);
}

}
