#include <iostream>
#include <list>
#include <stack> 
 
using namespace std;
 
class Grafo{
	int V; 
	list<int> *adj; 
 
public:
	Grafo(int V); 
	void adicionarAresta(int v1, int v2); 
 
	void dfs(int v);
};
 
Grafo::Grafo(int V){
	this->V = V;
	adj = new list<int>[V]; 
}
 
void Grafo::adicionarAresta(int v1, int v2){
	adj[v1].push_back(v2);
}
 
void Grafo::dfs(int v)
{
	stack<int> pilha;
	bool visitados[V]; 

	for(int i = 0; i < V; i++)
		visitados[i] = false;

	list<int> descoberta;
	list<int>::iterator it;
	list<int>::iterator it2;
 
	while(true)
	{
		if(!visitados[v])
		{
			descoberta.push_back(v);
			visitados[v] = true; 
			pilha.push(v); 
		}
 
		bool achou = false;

		for(it = adj[v].begin(); it != adj[v].end(); it++)
		{
			if(!visitados[*it]){
				achou = true;
				break;
			}
		}
 
		if(achou)
			v = *it; 
		else
		{
			pilha.pop();
			if(pilha.empty())
				break;
			v = pilha.top();
		}
	}
	for(it = descoberta.begin(); it != descoberta.end(); it++){
		cout << "Vertice " << *it << " visitado.  \n";	
	}	 
}
 
int main()
{
	int V = 11;
 
	Grafo grafo(V);
 
	grafo.adicionarAresta(0, 1);
	grafo.adicionarAresta(0, 2);
	grafo.adicionarAresta(0, 9);
	grafo.adicionarAresta(1, 3);
	grafo.adicionarAresta(3, 5);
	grafo.adicionarAresta(3, 6);
	grafo.adicionarAresta(2, 4);
	grafo.adicionarAresta(4, 7);
	grafo.adicionarAresta(4, 8);
	grafo.adicionarAresta(9, 10);
	
	grafo.dfs(0);
 
	return 0;
}
