#include<stdio.h>
#include<stdlib.h>

float fatorial(int n){
	if(n==0){
		return 1;
	}
	else{
		return n*fatorial(n-1);
	}
}

float soma(int c){
	if(c==1){
		return 1;
	}
	else{
		return (1/fatorial(c)) + soma(c-1);
	}
}

int main(){
	
	int a;
	float t;
	
	printf("Digite um numero inteiro para a soma:");
	scanf("%d",&a);
	
	t=soma(a);
	
	printf("O valor final e %.2f",t);

}
