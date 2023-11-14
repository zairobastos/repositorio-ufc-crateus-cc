#include <stdio.h>
#include <stdlib.h>
#include "esfera.h"
#include <math.h>

struct esfe{
float diametro;
};

 Esfera * inicializaEsfera(){
    Esfera * d = (Esfera*) malloc(sizeof(Esfera));
    return d;
}

void recebeDiametro(Esfera *d,float a){
    d->diametro = a;
    printf("Diametro adicionado com sucesso.\n");
}

float raio(Esfera *d){
    float b;
    b=d->diametro;
    b = b/2;
    return b;
}

float area(Esfera *d){
    float b;
    b=d->diametro;
    b = (4*3.14)* (pow (raio(d),2));
    return b;
}

float volume(Esfera *d){
    float b;
    b=d->diametro;
    b = ((4/3)*3.14)*(pow(raio(d),3));
    return b;
}
