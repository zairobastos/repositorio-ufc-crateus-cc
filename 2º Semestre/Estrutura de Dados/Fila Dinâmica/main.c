#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "Fd.h"

int main()
{
    setlocale(LC_ALL, "Potuguese");

     Line* line;
     elemento* valor;
     int numero, valor_busca, x, receb_busca;

     line = cria_line();

     for(int i = 0; i <= 3; i++){
       printf("Insira um valor: ");
       scanf("%d", &numero);

       valor = cria_elemento(numero);
       inserir(line, valor);
    }

    imprime(line);

    desenfilera(line);
    imprime(line);

    printf("\nDigite o valor que deseja saber a posição: ");
    scanf("%d", &valor_busca);

    x = cria_elemento(valor_busca);

    receb_busca = busca(line, x);
    printf("\nResultado da busca: %d", receb_busca);

    printf("\nTamanho da fila: %d", size(line));

    del_elementos(line);
    imprime(line);

    libera_ela(line);


    return 0;
}
