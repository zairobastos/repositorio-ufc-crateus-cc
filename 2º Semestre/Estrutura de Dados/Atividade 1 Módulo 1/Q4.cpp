#include<stdio.h>
#include<stdlib.h>

char trocavariavel(char *s1, char *s2){
	
	char aux;
	
	aux=*s1;
	*s1=*s2;
	*s2=aux;
	
}

int main(){
	
	char a,b;
	
	printf("Digite o primeiro valor:");
	scanf(" %c",&a);
	printf("Digite o segundo valor:");
	scanf(" %c",&b);
	
	trocavariavel(&a , &b);
	
	
	printf("O valor final fica %c e %c",a,b);
}
