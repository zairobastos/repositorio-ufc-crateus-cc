
typedef struct Elemento elemento;
typedef struct fDinamic Line;

Line* cria_line();
elemento* cria_elemento(int numero);
int vazia(Line* l1);
void inserir(Line* l1, elemento* num);
void desenfilera(Line* l1);
void imprime(Line* l1);
void libera_ela(Line* l1);
int busca(Line* l1, elemento* numero);
void isEmpty(Line* l1);
void del_elementos(Line* l1);
int size(Line* l1);
