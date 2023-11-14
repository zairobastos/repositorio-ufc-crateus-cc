#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
		
		int n = 10;
		
		Fila* fi = create(n);
		
		add(fi, 5);
		add(fi, 15);
		add(fi, 25);
		
		int primeiro = first(fi);
		
		int ultimo = last(fi);
		
		printf("Primeiro %i, Ultimo %i \n\n", primeiro, ultimo);
		
		int i = 0;
		
		printAll(fi);
		
		pop(fi);
		
		printf("\n----------------------------------\n");
		
		printAll(fi);
		
		return 1;
}
