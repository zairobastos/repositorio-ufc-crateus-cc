#include "lib.h"

UniaoBusca* ub_cria (int n){

	int i;
	UniaoBusca* ub = ( UniaoBusca*) malloc(sizeof ( UniaoBusca));
	ub->n = n;
	ub->v = (int *) malloc(ub->n* sizeof (int ));	
	
	for (i=0; i<ub->n; ++i)
		ub->v[i] = -1; 

	return ub;

}

void ub_libera ( UniaoBusca* ub){
	free(ub->v);
	free(ub);
}

int ub_busca ( UniaoBusca* ub, int x){

	
	int r = x;
	
	while (ub->v[r] >= 0)
		r = ub->v[r];
	
	
	while (ub->v[x] >= 0) {
		int p = ub->v[x];
		ub->v[x] = r;
		x = p;
	}
	
	return r;
}

int ub_uniao ( UniaoBusca* ub, int x, int y){

	x = ub_busca(ub,x);
	y = ub_busca(ub,y);
	if (x == y) 
		return x;
	

	
	if (ub->v[x] <= ub->v[y]) {
		ub->v[x] += ub->v[y]; 
		ub->v[y] = x; 
		return x;
	}
	
	else {
		ub->v[y] += ub->v[x]; 
		ub->v[x] = y; 
		return y;
	}

}
