#define L_ESQUERDO 0
#define L_DIREITO 1

struct no{
    char valor;
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
No * createRoot(arvoreBI *arv,char valor);
No * add(arvoreBI *arv,int lado,No *raiz,char valor);
void printAllPre(arvoreBI *arv);
void printAllIn(arvoreBI *arv);
void printAllPost(arvoreBI *arv);
int isEmpty(arvoreBI * arv);
int size(arvoreBI * arv);
void find(arvoreBI *arv,char valor);
void clear(arvoreBI * arv);


