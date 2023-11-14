#include <stdio.h>
#include <stdlib.h>
#include "circulo.h"
#include "circulo.c"


int main(){

float raio;

printf("Digite o raio:");
scanf("%f",&raio);

Circulo* circulo1 = criaCirculo();

setraio(circulo1,raio);
float comprimento1 = comprimento(circulo1);
float area1 = area(circulo1);

printf("O comprimento do circulo e %.2f e a area e %.2f\n",comprimento1,area1);

}
