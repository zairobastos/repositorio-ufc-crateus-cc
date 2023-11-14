#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "numeroComplexo.h"

struct numero{
float x;
float y;
};

Numero* criaNumero(){
return (Numero*) malloc(sizeof(Numero));
}
float getx(Numero* numero){
return numero->x;
}
void setx(Numero* numero,float x){
numero->x = x;
}
float gety(Numero* numero){
return numero->y;
}
void sety(Numero* numero,float y){
numero->y = y;
}
void destruir1 (Numero* numero){
    float *x;
     //= numero->x;
    free(x);
}
void destruir2(Numero* numero){
    free(numero);
}


float soma1(Numero* numero1, Numero* numero2){
return (numero1->x + numero2->x);
}
float soma2(Numero* numero1,Numero* numero2){
return (numero1->y + numero2->y);
}

float subtracao1(Numero* numero1, Numero* numero2){
return (numero1->x - numero2->x);
}
float subtracao2(Numero* numero1, Numero* numero2){
return (numero1->y - numero2->y);
}

float multiplicacao1(Numero* numero1, Numero* numero2){
return ((numero1->x * numero2->x) - (numero1->y * numero2->y))  ;
}
float multiplicacao2(Numero* numero1, Numero* numero2){
return ((numero1->x * numero2->y) + (numero1->y * numero2->x));
}
