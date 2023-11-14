#ifndef ENCADEIADA_H_INCLUDED
#define ENCADEIADA_H_INCLUDED

typedef struct Elemento elemento;
typedef struct Lista lista;

lista* create();
elemento* createElemento(int n);

int size(lista* q);
int isEmpty(lista* q);
int add(lista* q, elemento* num);
int remover(lista* q);
void imprime(lista* q);
int find(lista* q, elemento* num);
int clear(lista* q);

#endif // ENCADEIADA_H_INCLUDED
