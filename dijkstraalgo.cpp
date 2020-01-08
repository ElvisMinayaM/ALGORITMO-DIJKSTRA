#include <iostream>
#include <stdlib.h>
#include <list>
#include <queue>
#include <vector>
using namespace std;

vector<int> Matriz1;
vector<int> Matriz2;
class Grafo{ //ESTRUCTURA GRAFO
   list<pair<int, int> > *a;
   int V;
public:
   Grafo(int V){
      this->V = V;
      a=new list<pair<int, int> >[V]; //CONSTRUCTOR CON PARAMEROS PARA CREAR NUEVOS
   }
   
   int Dijkstra(int orig, int dest){ //ALGORITMO 
      int d[V];
      int visitados[V];
      priority_queue<pair<int, int>,
      vector<pair<int, int> >,greater<pair<int, int> > > vgrafos;
      for(int i=0;i<V;i++){
         d[i]=1000000;
         visitados[i] = false;}
      d[orig] = 0;
      vgrafos.push(make_pair(d[orig], orig));
      while(!vgrafos.empty()){
         pair<int, int> p = vgrafos.top();
         int u = p.second; 
         vgrafos.pop();
         if(visitados[u] == false){
            visitados[u] = true;
            list<pair<int, int> >::iterator it;
            for(it=a[u].begin();it != a[u].end(); it++){
               int v=it->first;
               int ca=it->second;
               if(d[v]>(d[u]+ca)){
                  d[v]=d[u]+ca;
                  vgrafos.push(make_pair(d[v],v));
               }
            }
         }
      }
      return d[dest];
   }
    // FUNCION PARA HACER LAS UNIONES DE ARISTAS
   void AArista(int v1, int v2, int peso){
      a[v1].push_back(make_pair(v2,peso));
      Matriz1.push_back(v1);
      Matriz2.push_back(v2);
   }
};

// GENERADOR DE MATRIZ DE ADYACENCIA
int GMAdyacencia(){
   cout<<endl;
   int ite=0;
   for (int i=0;i<Matriz1.size();i++){
      for (int j=0;j<Matriz2.size();j++){
         if(Matriz1[ite]==i and Matriz2[ite]==j){
            cout<<"1";
            ite++;
         }else{
            cout<<"0";
         }
      }
      cout<<endl;
   }
}

int main(){
   //aqui creamos un grafo de 6 vertices
   Grafo G(6);
   //AQUI TENEMOS LAS ARISTAS (CONEXIONES)
   G.AArista(0,1,1),
   G.AArista(1,2,1);
   G.AArista(2,3,1);
   G.AArista(4,5,1); 
   G.AArista(0,4,1);
   G.AArista(4,3,0);
   G.AArista(3,5,6);
   G.AArista(1,5,8);
   cout<<endl;
   cout<<"COSTO: "<<G.Dijkstra(0,5)<<endl;//aqui solicitamos el camino corto del vertice cero al cinco
   GMAdyacencia();
   return 0;
}  