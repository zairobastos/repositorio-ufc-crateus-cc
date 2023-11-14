typedef struct {
	int n;
	int k; 
	int* dados; 
} ListaEstaticaOrdenada;

ListaEstaticaOrdenada* create(int n);

int add(ListaEstaticaOrdenada* ed, int e);

void printAll(ListaEstaticaOrdenada* ed);


