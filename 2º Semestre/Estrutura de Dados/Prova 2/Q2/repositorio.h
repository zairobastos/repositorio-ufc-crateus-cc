#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct Repositorio repositorio;

repositorio * inicializaLista();
void create(repositorio *a,int n);
void ini(repositorio *a);
int estaCheio(repositorio *a);
int estaVazio(repositorio *a);
int tamanho(repositorio *a);
int add(repositorio *a,int e,int c);
int remover(repositorio *a,int e);
void imprime(repositorio *a);
int pesquisarCodigo(repositorio *a,int e);
int pesquisarValor(repositorio *a,int e);
void esvaziar(repositorio *a);
int tratar(repositorio *a);


#endif // PILHA_H_INCLUDED
