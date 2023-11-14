#include <stdio.h>
#include <stdlib.h>
#include "Pedido.h"
 
typedef struct {
	Pedido** repositorio; //como iremos trabalhar com um vetor de outro tipo estruturado, fazemos um vetor de ponteiro para ponteiro para o objeto estruturado.
	int n;
	int k;	
} Bag;

Bag* create(int n);

int add(Bag* bag, Pedido* p);

Pedido* get(Bag* bag);

void printBag(Bag* bag);
