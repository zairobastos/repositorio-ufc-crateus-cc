#ifndef MERGE_H_INCLUDED
#define MERGE_H_INCLUDED

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
void mergeSort(vetor *v,int esquerda, int direita);

#endif // MERGE_H_INCLUDED
