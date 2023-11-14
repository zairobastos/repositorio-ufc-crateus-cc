#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct ponto{
	float x,y;
};

void dis(struct ponto *a/*,struct ponto *b, struct ponto *c, struct ponto *d, struct ponto *e*/){
 
	float v1,v2,v3,v4,l1,l2,p1,p2;
	int i;
	
	for(i=1;i<5;i++){
	
	if(i==1){
		v1=sqrt(pow(a[i].x - a[0].x,2) + pow(a[i].y - a[0].y,2));
	}
	else if(i==2){
		v2=sqrt(pow(a[i].x - a[0].x,2) + pow(a[i].y - a[0].y,2));
	}
	else if(i==3){
		v3=sqrt(pow(a[i].x - a[0].x,2) + pow(a[i].y - a[0].y,2));
	}
	else if(i==4){
		v4=sqrt(pow(a[i].x - a[0].x,2) + pow(a[i].y - a[0].y,2));
	}
	}
	
	if(v1<v2 && v1<v3 && v1<v4){
		p1=a[1].x; p2=a[1].y;
	}
	else if(v2<v1 && v2<v3 && v2<v4){
		p1=a[2].x; p2=a[2].y;
	}
	else if(v3<v1 && v3<v2 && v3<v4 ){
		p1=a[3].x; p2=a[3].y;
	}
	else if(v4<v1 && v4<v2 && v4<v3 ){
		p1=a[4].x; p2=a[4].y;
	}
	if(v1>v2 && v1>v3 && v1>v4 ){
		l1=a[1].x; l2=a[1].y;
	}
	else if(v2>v1 && v2>v3 && v2>v4 ){
		l1=a[2].x; l2=a[2].y;
	}
	else if(v3>v1 && v3>v2 && v3>v4 ){
		l1=a[3].x; l2=a[3].y;
	}
	else if(v4>v1 && v4>v2 && v4>v3 ){
		l1=a[4].x; l2=a[4].y;
	}
	
	printf("O ponto mais proximo do primeiro ponto e (%.2f,%.2f)\n",p1,p2);
	printf("O ponto mais longe do primeiro ponto e (%.2f,%.2f)\n",l1,l2);
	
	free(a);
	
}

int main(){
	
	struct ponto *c;
	int i;
	
	c = (struct ponto*) malloc(sizeof(struct ponto*) * 5);
	
	for(i=0;i<5;i++){
		printf("Digite o ponto do x:");
		scanf("%f",&c[i].x);
		printf("Digite o ponto do y:");
		scanf("%f",&c[i].y);
	}
	
	dis(c);
	free(c);
}
