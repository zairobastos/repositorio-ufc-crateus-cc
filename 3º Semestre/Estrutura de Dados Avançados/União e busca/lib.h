#include<stdlib.h>
#include<stdio.h>

struct UniaoBusca {
	int n;
	int * v; 
};

UniaoBusca* ub_cria (int n);
void ub_libera ( UniaoBusca* ub);
int ub_busca ( UniaoBusca* ub, int x);
int ub_uniao ( UniaoBusca* ub, int x, int y);



