#ifndef CODIGO_H_INCLUDED
#define CODIGO_H_INCLUDED

typedef struct Catalogo catalogo;

catalogo * inicializaLista();
void create(catalogo *a,int n);
void ini(catalogo *a);
int catalogoCheio(catalogo *a);
int catalogoVazio(catalogo *a);
int tamanho(catalogo *a);
int adicionar(catalogo *a,int e,int c);
int removerVent(catalogo *a,int e);
void imprime(catalogo *a);
int catalogoPes(catalogo *a,int e);
void limparCatalogo(catalogo *a);
int ordenar(catalogo *a);

#endif // CODIGO_H_INCLUDED
