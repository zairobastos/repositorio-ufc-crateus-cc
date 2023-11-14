#include <stdio.h>
#include <stdlib.h>
#include "esfera.h"

int main(){

    float dia;

    printf("O valor usado para pi=3,14.\n");

    printf("Digite o diametro da esfera:");
    scanf("%f",&dia);

    Esfera *w = inicializaEsfera();

    recebeDiametro(w,dia);
    printf("O raio e:%.2f\n",raio(w));
    printf("A area e:%.2f\n",area(w));
    printf("O volume e:%.2f\n",volume(w));
}
