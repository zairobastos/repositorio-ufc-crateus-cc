#include<cstdio>
#include<queue>
#include<cstring>
#include<vector>
#include<iostream>
using namespace std;
int c[10][10];
int arestasPre[0][5];
int fluxoPassado[10][10];
vector<int> g[10];
int parList[10];
int caminhoAtual[10];

int bfs(int fonte, int sumidouro)
{
   memset(parList, -1, sizeof(parList));
   memset(caminhoAtual, 0, sizeof(caminhoAtual));
   queue<int> q;
   q.push(fonte);
   parList[fonte] = -1;
   caminhoAtual[fonte] = 999;
   while(!q.empty())
   {
      int noAtual = q.front();
      q.pop();
      for(int i=0; i<g[noAtual].size(); i++)
      {
         int to = g[noAtual][i];
         if(parList[to] == -1)
         {
            if(c[noAtual][to] - fluxoPassado[noAtual][to] > 0)
            {
               parList[to] = noAtual;
               caminhoAtual[to] = min(caminhoAtual[noAtual],
               c[noAtual][to] - fluxoPassado[noAtual][to]);
               if(to == sumidouro)
               {
                  return caminhoAtual[sumidouro];
               }
               q.push(to);
            }
         }
      }
   }
   return 0;
}
int edmondsKarp(int fonte, int sumidouro)
{
   int fluxoMaximo = 0;
   while(true)
   {
      int fluxo = bfs(fonte, sumidouro);
      if (fluxo == 0)
      {
         break;
      }
      fluxoMaximo += fluxo;
      int noAtual = sumidouro;
      while(noAtual != fonte)
      {
         int noAnterior = parList[noAtual];
         fluxoPassado[noAnterior][noAtual] += fluxo;
         fluxoPassado[noAtual][noAnterior] -= fluxo;
         noAtual = noAnterior;
      }
   }
return fluxoMaximo;
}
int main(){

   int fonte = 0, sumidouro = 5;
   
   c[0][1] = 16;
   g[0].push_back(1);
   g[1].push_back(0);
   c[0][2] = 13;
   g[0].push_back(2);
   g[2].push_back(0);
   c[1][3] = 12;
   g[1].push_back(3);
   g[3].push_back(1);
   c[2][1] = 4;
   g[2].push_back(1);
   g[2].push_back(1);
   c[2][4] = 14;
   g[2].push_back(4);
   g[2].push_back(4);
   c[3][2] = 9;
   g[3].push_back(2);
   g[2].push_back(3);
   c[3][5] = 20;
   g[3].push_back(5);
   g[3].push_back(5);
   c[4][3] = 7;
   g[4].push_back(3);
   g[3].push_back(4);
   c[4][5] = 4;
   g[4].push_back(5);
   g[5].push_back(4);
   
   int fluxoMaximo = edmondsKarp(fonte, sumidouro);
   cout<<endl<<endl<<"O fluxo maximo e:"<<fluxoMaximo<<endl;
}
