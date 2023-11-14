#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "circulo.h"
#define PI 3.14

struct circulo{
float raio;
};

Circulo* criaCirculo(){
return (Circulo*) malloc (sizeof(Circulo));
}
float getraio(Circulo* circulo){
return circulo->raio;
}
void setraio(Circulo* circulo,float raio){
circulo->raio = raio;
}
float comprimento(Circulo* circulo){
return (2)*(PI)*(circulo->raio);
}
float area(Circulo* circulo){
return (PI)*pow((circulo->raio),2);
}

