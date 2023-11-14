 #include <stdio.h>
 #include <stdlib.h>
 #include "Pedido.h"
 
 Pedido* createPedido(int c, double v){
 	
 	Pedido * p = (Pedido*) malloc(sizeof(Pedido));
 	
 	p->codigo = c;
 	p->valor = v;
 	
 	return p;
 	
 }
 
 void printPedido(Pedido* p){
 	
 	if(p != NULL)
 		printf("Pedido [%i, %f]\n", p->codigo, p->valor);
 	
 }
 
