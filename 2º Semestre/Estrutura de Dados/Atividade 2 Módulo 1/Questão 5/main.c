#include <stdio.h>
#include <stdlib.h>
#include "cubo.h"
#include "cubo.c"

int main(){

int a;

Cubo* cubo1 = criaCubo();

printf("Digite o tamanho da aresta do cubo:");
scanf("%d",&a);

setaresta(cubo1,a);

float areaa = area(cubo1);
float volumee = volume(cubo1);
float tamanhoo = tamanho(cubo1);

printf("A area do cubo e:%.2f\n",areaa);
printf("A volume do cubo e:%.2f\n",volumee);
printf("O tamanho de cada lado do cubo e:%.2f\n",tamanhoo);

}
