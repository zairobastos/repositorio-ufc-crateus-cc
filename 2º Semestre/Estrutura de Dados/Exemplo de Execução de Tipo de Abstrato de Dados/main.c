//Fonte do arquivo main.c:
#include <stdio.h>
#include <stdlib.h>
#include "aluno.h"
#include "aluno.c"

int main(){
Aluno* aluno1 = criaAluno();
setNome(aluno1, "Joao");
setNota1(aluno1, 5);
setNota2(aluno1, 8);
float media = calcularMedia(aluno1);
char *nome = getNome(aluno1);
printf("A media de %s foi: %f",nome, media);
return 1;
}
