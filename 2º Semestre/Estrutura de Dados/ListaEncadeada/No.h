struct no{
 	int valor;
	struct no *proximo;
 } ;

typedef struct no No;
 
No* createNo(int v, No* proximo);
 
void printNo(No* no);
 
void freeNo(No *no);
