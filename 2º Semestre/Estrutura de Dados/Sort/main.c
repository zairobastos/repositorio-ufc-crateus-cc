#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	Vetor* v = create(5);
	
	add(v, 10, 500.0);
	add(v, 7, 400.0);
	add(v, 2, 300.0);
	add(v, 11, 200.0);
	add(v, 1, 200.0);
	
	printVetor(v);
	
	insertionSort(v);
	
	printVetor(v);
	
	return 0;
}
