#ifndef SELECTION_H_INCLUDED
#define SELECTION_H_INCLUDED

struct Produto{
    int codigo;
    float valor;
};

typedef struct Produto produto;

struct Vetor{
    produto ** vet;
    int tam;
    int n;
};

typedef struct Vetor vetor;

vetor * create(int n);
void add(vetor *v, int codigo,float valor);
void imprime (vetor * v);
void selectionSort(vetor *v);

#endif // SELECTION_H_INCLUDED
