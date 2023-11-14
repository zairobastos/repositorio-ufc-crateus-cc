#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "cubo.h"

struct cubo{
float aresta
};

Cubo* criaCubo(){
return (Cubo*) malloc(sizeof(Cubo));
}

float getaresta(Cubo* cubo){
return cubo->aresta;
}
void setaresta(Cubo* cubo,float aresta){
cubo->aresta = aresta;
}

float area(Cubo* cubo){
return pow(cubo->aresta,2) * 6;
}

float volume(Cubo* cubo){
return pow(cubo->aresta,3);
}

float tamanho(Cubo* cubo){
return pow(cubo->aresta,2);
}
