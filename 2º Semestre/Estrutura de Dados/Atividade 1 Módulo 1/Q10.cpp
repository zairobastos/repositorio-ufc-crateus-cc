#include <stdio.h>
#include <stdlib.h>

void alterav(int *d,int h,int g){
	
	int *y,aux1;
	
	y = d;
	
	d = (int*) realloc(d,h+1*sizeof(int));
	
	for(int i=0 ;i<h+1;i++){
		if(y[i]=d[i]);
		else{
			d[i]=g;
		}
	}
	
	for(int e=0;e<h+1;e++){
		for(int f=0;f<h+1;f++){
		if(d[e] < d[f]){
			aux1 = d[e];
			d[e] = d[f];
			d[f] = aux1;
		}
		}
	}
	
	for(int c=0;c<h+1;c++){
		printf("valor de %d final: %d\n",c,d[c]);
	}
	
	free(d);
	free(y);	
}

int main(){
	
	int *a,t,i,e,c,aux,x;
	
	printf("Digite o tamanho do vetor:");
	scanf("%d",&t);
	
	printf("\n");
	
	a =(int*) malloc(sizeof(int)*t);
	
	printf("Digite os valores\n");
	
	for(i=0;i<t;i++){
		printf("valor %d:",i);
		scanf("%d",&a[i]);
	}
	
	for(e=0;e<t;e++){
		for(int f=0;f<t;f++){
		if(a[e] < a[f]){
			aux = a[e];
			a[e] = a[f];
			a[f] = aux;
		}
		}
	}
	printf("\n");
	for(c=0;c<t;c++){
		printf("valor de %d final: %d\n",c,a[c]);
	}
	printf("\n");
	
	printf("Digite o valor a ser inserido:");
	scanf("%d",&x);
	printf("\n");
	
	alterav(a,t,x);

	free(a);
}
