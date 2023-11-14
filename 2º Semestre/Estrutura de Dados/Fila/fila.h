typedef struct fila Fila;

Fila* create(int n);

int add(Fila* fi, int e);

int pop(Fila* fi);

int first(Fila* fi);

int last(Fila* fi);

int isEmpty(Fila* fi);

int isFull(Fila* fi);

void printAll(Fila* fi);
