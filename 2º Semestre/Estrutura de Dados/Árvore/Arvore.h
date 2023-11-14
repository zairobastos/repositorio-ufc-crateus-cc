	#define LADO_ESQ 0 //A CRIAÇÃO DESTAS CONSTANTES EVITA O USO DE NÚMEROS
	#define LADO_DIR 1 //MÁGICOS E PADRONIZA A REFERÊNCIA A ESTA INFORMAÇÃO.

	struct no{
		int valor;
		struct no *filhoEsquerda;
		struct no *filhoDireita;
	 } ;

	typedef struct no No; 

	typedef struct {
		No *raiz;
	} ArvoreBinaria;
	
	ArvoreBinaria *criar() ;
	
	No *criarRaiz(ArvoreBinaria *arvore, int valor) ;

	No *inserir_filho(int lado, No *v, int w) ;
	 
	void pre_ordem_aux(No *raiz) ;
	
	void pre_ordem(ArvoreBinaria *arvore);

	void em_ordem_aux(No *raiz) ;
	
	void em_ordem(ArvoreBinaria *arvore) ;
	
	void pos_ordem_aux(No *raiz) ;

	void pos_ordem(ArvoreBinaria *arvore) ;

