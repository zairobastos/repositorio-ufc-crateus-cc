#include<stdio.h>
#include<stdlib.h>

void lervalor(float *q, int *r){
	
	int cont=0;
	
	do{		
		printf("Digite o valor:");
		scanf("%f",&q[cont]);
		cont++;
		
	}while(cont <= *r);
	
	free(q);
	
}

int main(){
	
	float *a;
	int i,n;
	
	printf("Digite quantos valores irao ser digitados:\n");
	scanf("%d",&n);
	n-=1;
	a =(float*) malloc(sizeof(float)*n);
	
	lervalor(a,&n);
	
	for(i=0;i<=n;i++){
		printf("%.2f\n",a[i]);
	}
	
	free(a);
}
