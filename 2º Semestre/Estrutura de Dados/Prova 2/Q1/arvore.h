#ifndef ARVORE_H_INCLUDED
#define ARVORE_H_INCLUDED
#define L_ESQUERDO 0
#define L_DIREITO 1

struct no{
    int valor;
    struct no * filhoEsquerda;
    struct no * filhoDireita;
};

typedef struct no No;

typedef struct arvoreBinaria{
    int tam;
    int nivel;
    No * raiz;
}arvoreBI;

arvoreBI * create();
No * createRoot(arvoreBI *arv,int valor);
No * add(arvoreBI *arv,No *raiz,int valor);
void printAllPre(arvoreBI *arv);
void printAllIn(arvoreBI *arv);
void printAllPost(arvoreBI *arv);
int isEmpty(arvoreBI * arv);
int size(arvoreBI * arv);
void find(arvoreBI *arv,int valor);
void clear(arvoreBI * arv);


#endif // ARVORE_H_INCLUDED
