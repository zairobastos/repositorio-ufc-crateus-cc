#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct data{
	int dia;
	int mes;
	int ano;
};

struct pessoa{
	char nome[100];
	int dian;
	int mesn;
	int anon;
};

void dadosd(struct data *dd,struct pessoa *nn,struct data *cc,struct pessoa *ee){
	
	int a;
	
	printf("Digite a data atual em numero\n");
	
	printf("Dia:");
	scanf("%d",&dd->dia);
	do{
	if(dd->dia < 1 || dd->dia > 30){
		printf("Dia invalido\n");
		printf("Digite novamente\n");
		
		printf("Dia:");
		scanf("%d",&dd->dia);
	}
	else{
		break;
	}
	}while(a);
	
	printf("Mes:");
	scanf("%d",&dd->mes);
	do{
	if(dd->mes < 1 || dd->mes > 12){
		printf("Mes invalido\n");
		printf("Digite novamente\n");
		
		printf("Mes:");
		scanf("%d",&dd->mes);
	}
	else{
		break;
	}
	}while(a);
	
	printf("Ano:");
	scanf("%d",&dd->ano);
	
	printf("-------------------------------------------------------------\n");
	
	printf("Digite o nome:");
	scanf(" %[^\n]s",&nn->nome);
	
	printf("Digite a data de nascimento em numero\n");
	
	printf("Dia:");
	scanf("%d",&nn->dian);
	do{
	if(nn->dian < 1 || nn->dian > 30){
		printf("Dia invalido\n");
		printf("Digite novamente\n");
		
		printf("Dia:");
		scanf("%d",&nn->dian);
	}
	else{
		break;
	}
	}while(a);
	
	printf("Mes:");
	scanf("%d",&nn->mesn);
	do{
	if(nn->mesn < 1 || nn->mesn > 12){
		printf("Mes invalido\n");
		printf("Digite novamente\n");
		
		printf("Mes:");
		scanf("%d",&nn->mesn);
	}
	else{
		break;
	}
	}while(a);
	
	printf("Ano:");
	scanf("%d",&nn->anon);
	
	printf("-------------------------------------------------------------\n");
	
	printf("Digite o nome:");
	scanf(" %[^\n]s",&ee->nome);
	
	printf("Digite a data de nascimento em numero\n");
	printf("Dia:");
	scanf("%d",&ee->dian);
	do{
	if(ee->dian < 1 || ee->dian > 30){
		printf("Dia invalido\n");
		printf("Digite novamente\n");
		
		printf("Dia:");
		scanf("%d",&ee->dian);
	}
	else{
		break;
	}
	}while(a);
	
	printf("Mes:");
	scanf("%d",&ee->mesn);
	do{
	if(ee->mesn < 1 || ee->mesn > 12){
		printf("Mes invalido\n");
		printf("Digite novamente\n");
		
		printf("Mes:");
		scanf("%d",&ee->mesn);
	}
	else{
		break;
	}
	}while(a);
	
	printf("Ano:");
	scanf("%d",&ee->anon);	
	
		if(nn->dian<ee->dian && nn->mesn<ee->mesn && nn->anon<ee->anon){
			printf("A pessoa mais velha e %s\n",nn->nome);	
		}
		else if(nn->dian>ee->dian && nn->mesn<ee->mesn && nn->anon<ee->anon){
			printf("A pessoa mais velha e %s\n",nn->nome);
		}
		else if(nn->dian>ee->dian && nn->mesn>ee->mesn && nn->anon<ee->anon){
			printf("A pessoa mais velha e %s\n",nn->nome);
		}
		else if(nn->dian<ee->dian && nn->mesn==ee->mesn && nn->anon==ee->anon){
			printf("A pessoa mais velha e %s\n",nn->nome);
		}
		else if(nn->dian<ee->dian && nn->mesn<ee->mesn && nn->anon==ee->anon){
			printf("A pessoa mais velha e %s\n",nn->nome);
		}
		else if(nn->dian==ee->dian && nn->mesn==ee->mesn && nn->anon<ee->anon){
			printf("A pessoa mais velha e %s\n",nn->nome);
		}
		
		if(nn->dian>ee->dian && nn->mesn>ee->mesn && nn->anon>ee->anon){
			printf("A pessoa mais velha e %s\n",ee->nome);	
		}
		else if(nn->dian<ee->dian && nn->mesn>ee->mesn && nn->anon>ee->anon){
			printf("A pessoa mais velha e %s\n",ee->nome);
		}
		else if(nn->dian<ee->dian && nn->mesn<ee->mesn && nn->anon>ee->anon){
			printf("A pessoa mais velha e %s\n",ee->nome);
		}
		else if(nn->dian>ee->dian && nn->mesn==ee->mesn && nn->anon==ee->anon){
			printf("A pessoa mais velha e %s\n",ee->nome);
		}
		else if(nn->dian>ee->dian && nn->mesn>ee->mesn && nn->anon==ee->anon){
			printf("A pessoa mais velha e %s\n",ee->nome);
		}
		else if(nn->dian==ee->dian && nn->mesn==ee->mesn && nn->anon>ee->anon){
			printf("A pessoa mais velha e %s\n",ee->nome);
		}
		
		else if(nn->dian==ee->dian && nn->mesn==ee->mesn && nn->anon==ee->anon){
			printf("As duas pessoas tem a mesma idade.\n");
		}	
	
}

int main(void){
	
	struct data d;
	struct pessoa n;
	struct data c;
	struct pessoa e;
	
	dadosd(&d,&n,&c,&e);
}
