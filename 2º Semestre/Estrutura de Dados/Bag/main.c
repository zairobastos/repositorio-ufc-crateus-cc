#include <stdio.h>
#include <stdlib.h>
#include "Bag.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	srand(time(NULL));
	
	Pedido *p1 = createPedido(1212, 300.00);

	Pedido *p2 = createPedido(3232, 400.00);

	Pedido *p3 = createPedido(5252, 500.00);
	
	Bag* bag = create(10);
	
	printBag(bag);
	
	add(bag, p1);
	add(bag, p2);
	add(bag, p3);
	
	printBag(bag);
	
	Pedido* pB = get(bag);
	
	printPedido(pB);
	
	printBag(bag);
		
	return 0;
}
