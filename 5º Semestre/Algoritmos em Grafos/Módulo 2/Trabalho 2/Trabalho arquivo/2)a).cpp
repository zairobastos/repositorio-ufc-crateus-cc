#include <iostream>
#include <vector>
#include <algorithm> 
#include <string.h> 
using namespace std;

class Aresta
{
	int vertice1, vertice2, peso;

public:

	Aresta(int v1, int v2, int peso)
	{
		vertice1 = v1;
		vertice2 = v2;
		this->peso = peso;
	}

	int obterVertice1()
	{
		return vertice1;
	}

	int obterVertice2()
	{
		return vertice2;
	}

	int obterPeso()
	{
		return peso;
	}

	bool operator < (const Aresta& aresta2) const
	{
		return (peso < aresta2.peso);
	}
};

class Grafo
{
	int V; 
	vector<Aresta> arestas; 

public:

	Grafo(int V)
	{
		this->V = V;
	}

	void adicionarAresta(int v1, int v2, int peso)
	{
		Aresta aresta(v1, v2, peso);
		arestas.push_back(aresta);
	}

	int buscar(int subset[], int i)
	{
		if(subset[i] == -1)
			return i;
		return buscar(subset, subset[i]);
	}

	void unir(int subset[], int v1, int v2)
	{
		int v1_set = buscar(subset, v1);
		int v2_set = buscar(subset, v2);
		subset[v1_set] = v2_set;
	}

	void kruskal()
	{
		vector<Aresta> arvore;
		int size_arestas = arestas.size();

		sort(arestas.begin(), arestas.end());

		int * subset = new int[V];

		memset(subset, -1, sizeof(int) * V);
		
		int soma_pesos1 = 0,soma_pesos2 = 0, soma_t;
		int size_arvore=0;

		for(int i = 0; i < V; i++){
			int v1 = buscar(subset, arestas[i].obterVertice1());
			int v2 = buscar(subset, arestas[i].obterVertice2());

			if(v1 != v2){
				arvore.push_back(arestas[i]);
				unir(subset, v1, v2); 
			}
			size_arvore = 0;
			size_arvore = arvore.size();
			if(i == V-3){
				for(int j = 0 ; j <  size_arvore; j++){
					soma_pesos1 = soma_pesos1 + arvore[j].obterPeso();
 				}	
			}
			if(i == V-1){
				for(int l = 0 ; l <  size_arvore; l++){
					soma_pesos2 = soma_pesos2 + arvore[l].obterPeso();
				}	
			}
			if(soma_pesos2 > soma_pesos1){
				cout << "Erro: existe um ciclo negativo no grafo" <<"\n";
				break;
			}
			else if(i == V-1){
				size_arvore = arvore.size();
				char a = 'A';
				char b = 'D';
				for(int k = 0; k < size_arvore; k++){
					char v1 = 'A' + arvore[k].obterVertice1();
					char v2 = 'A' + arvore[k].obterVertice2();
					if(a == v1 && b == v2){
						cout << "(" << v1 << ", " << v2 << ") = " << arvore[k].obterPeso() << "\n";
						break;
					}
					else if(a == v1){
						cout << "(" << v1 << ", " << v2 << ") = " << arvore[k].obterPeso() << "\n";
					}
					else if(b == v2){
						cout << "(" << v1 << ", " << v2 << ") = " << arvore[k].obterPeso() << "\n";
						break;
					}
					else if(a+1 == v1){
						cout << "(" << v1 << ", " << v2 << ") = " << arvore[k].obterPeso() << "\n";
					}
					soma_t = soma_t + arvore[k].obterPeso();
				}
			}
		}
	}
};

int main(int argc, char *argv[])
{
	Grafo g(7);
	
	//Grafo normal.
	/*g.adicionarAresta(0, 1, 6);
	g.adicionarAresta(0, 3, 8);
	g.adicionarAresta(1, 2, 9);
	g.adicionarAresta(1, 3, 7);
	g.adicionarAresta(1, 4, 7);
	g.adicionarAresta(2, 4, 5);
	g.adicionarAresta(3, 4, 15);
	g.adicionarAresta(3, 5, 6);
	g.adicionarAresta(4, 5, 8);
	g.adicionarAresta(4, 6, 9);
	g.adicionarAresta(5, 6, 11);*/
	
	//Grafo com ciclo negativo.
	g.adicionarAresta(0, 1, -6);
	g.adicionarAresta(0, 3, -8);
	g.adicionarAresta(1, 2, -9);
	g.adicionarAresta(1, 3, -7);
	g.adicionarAresta(1, 4, 7);
	g.adicionarAresta(2, 4, 5);
	g.adicionarAresta(3, 4, 15);
	g.adicionarAresta(3, 5, 6);
	g.adicionarAresta(4, 5, 8);
	g.adicionarAresta(4, 6, 9);
	g.adicionarAresta(5, 6, 11);
	
	g.kruskal(); 
	
	return 0;
}
