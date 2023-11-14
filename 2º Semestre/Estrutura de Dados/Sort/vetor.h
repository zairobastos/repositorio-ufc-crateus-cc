struct produto{
	int codigo;
	float valor;
};

typedef struct produto Produto; 

typedef struct{
	Produto ** dados;
	int n;
	int contador;
} Vetor;

Vetor* create(int n);

int* add(Vetor* v, int codigo, float valor);

void insertionSort(Vetor* v) ;  

void printVetor(Vetor* v);

Produto* createProduto(int codigo, float valor);
