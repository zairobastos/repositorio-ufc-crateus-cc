#include<stdio.h>
#include<stdlib.h>

int fatorial(int n){
	if(n==0){
		return 1;
	}
	else{
		return n*fatorial(n-1);
	}
}

int soma(int c){
	if(c==1){
		return 1;
	}
	else{
		return fatorial(c) + soma(c-1);
	}
}

int main(){
	
	int x,t;
	
	printf("Digite um numero inteiro para calcular o superfatorial:");
	scanf("%d",&x);
	
	t=soma(x);
	
	printf("O valor final e %d",t);

}
