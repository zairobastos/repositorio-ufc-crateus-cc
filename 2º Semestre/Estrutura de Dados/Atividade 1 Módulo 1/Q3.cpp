#include<stdio.h>
#include<stdlib.h>

float trocavariavel(float *n1, float *n2){
	
	int aux;
	
	aux=*n1;
	*n1=*n2;
	*n2=aux;		
}

int main(){
	
	float x,y,aux;
	
	printf("Digite o primeiro valor:");
	scanf("%f",&x);
	printf("Digite o segundo valor:");
	scanf("%f",&y);
	
	trocavariavel(&x,&y);
	
	printf("O valor final fica %.2f e %.2f",x,y);
}
