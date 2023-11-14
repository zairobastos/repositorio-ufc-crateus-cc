#include <stdio.h>
#include <stdlib.h>

/***************** Arvore.h *********************/

typedef struct _arvore {
   int info;
   struct _arvore *esq;
   struct _arvore *dir;
} Arvore;

Arvore* cria_arv_vazia ();

Arvore* Remover (Arvore *a, int v);

void destroi_arv (Arvore *arv);

Arvore* constroi_arv (int elem, Arvore *esq, Arvore *dir);

int min (Arvore *a);

int max (Arvore *a);

void imprime_decrescente (Arvore *a);

int maior_ramo (Arvore *a);


/***************** Arvore.c *********************/

/*Cria uma arvore vazia!*/
Arvore* cria_arv_vazia () {
   return NULL;
}

/*Destroi uma arvore!*/
void destroi_arv (Arvore *arv) {
   if (arv != NULL) {
      destroi_arv (arv->esq);
      destroi_arv (arv->dir);
      free(arv);
   }
}

/*Cria um no em uma arvore!*/
Arvore* inserir (Arvore *a, int v){
    if(a == NULL){
        a=(Arvore*)malloc(sizeof(Arvore));
        a->info = v;
        a->esq = NULL;
        a->dir = NULL;
    }
    else if(v < a->info){
        a->esq = inserir(a->esq,v);
    }
    else{
        a->dir = inserir(a->dir,v);
    }
    return a;
}



void pre_ordem (Arvore *arv) {
    if (arv != NULL){
       printf ("%d, ", arv->info);
       pre_ordem (arv->esq);
       pre_ordem (arv->dir);

    }
}

void in_ordem (Arvore *arv) {
   if (arv != NULL) {
      in_ordem (arv->esq);
      printf ("%d, ", arv->info);
      in_ordem (arv->dir);
   }
}

void pos_ordem (Arvore *arv){
    if (arv != NULL){
        pos_ordem (arv->esq);
        pos_ordem (arv->dir);
        printf("%d, ", arv->info);
    }
}

int buscar (Arvore *a, int v){
    if(a==NULL){
        return 0;
    }
    else if(v < a->info){
        return buscar(a->esq,v);
    }
    else if(v > a->info){
        return buscar(a->dir,v);
    }
    else{
        return 1;
    }
}

int min (Arvore *a){
    if( a->esq != NULL){
        return min(a->esq);
    }
    else{
         return a->info;
    }
}

int max (Arvore *a){
    if (a->dir != NULL){
        return max(a->dir);
    }
    else{
        return a->info;
    }
}

Arvore* Remover (Arvore *a, int v){
    if(a == NULL){
        return NULL;
    }
    else{
        if(a->info >v){
            a->esq = Remover (a->esq,v);
        }
        else if (a->info <v){
            a->dir = Remover (a->dir,v);
        }
        else{
            if((a->esq == NULL) && (a->dir == NULL)){
                free(a);
                a=NULL;
            }
            else if(a->dir == NULL){
                Arvore *tmp = a;
                a = a -> esq;
                free (tmp);
            }
            else if(a->esq == NULL){
                Arvore *tmp = a;
                a = a -> dir;
                free (tmp);
            }
            else{
                Arvore *tmp = a->esq;
                while(tmp->dir != NULL){
                    tmp=tmp->dir;
                }
                a->info = tmp->info;
                tmp->info = v;
                a->esq = Remover(a->esq,v);
            }
        }
    }
    return a;
}


void imprime_decrescente (Arvore *arv){
    if (arv != NULL){
        printf("%d, ", max(arv));
        imprime_decrescente(Remover(arv, max(arv)));

    }
}


int contarNos(Arvore *a){
   if(a == NULL)
        return 0;
   else
        return 1 + contarNos(a->esq) + contarNos(a->dir);
}

int maior(int a, int b){
    if(a > b)
        return a;
    else
        return b;
}

int maior_ramo(Arvore *a){
   if((a == NULL)){
        return 0;
   }
   else{
        return maior(maior_ramo(a->dir) +a-> info, maior_ramo(a->esq) + a->info);
   }
}


/****************** Prog.c **********************/

int main () {

Arvore *a = cria_arv_vazia ();

a = inserir (a, 50);
a = inserir (a, 30);
a = inserir (a, 90);
a = inserir (a, 20);
a = inserir (a, 40);
a = inserir (a, 95);
a = inserir (a, 10);
a = inserir (a, 35);
a = inserir (a, 45);




printf("%d",maior_ramo(a));

return 0;


}
