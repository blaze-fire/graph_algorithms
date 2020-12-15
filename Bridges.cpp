//Finds all the bridges on an undirected graph.
#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Bridge{
  const static int numVertices = 9;
  std::array <int,numVertices>  ids,low;
  bool visited[numVertices] = {false};
  vector <int> g[numVertices];
  vector <int> bridges; 
  int id = 0;

  public:

  void addEdge(int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);
  }
  
  void dfs(int at, int parent){
    visited[at] = true;
    id++;
    low[at] = ids [at] =id;

    for(auto to : g[at]){
      if(to == parent)  continue;

      if(!visited[to]){
        dfs(to,at);
        low[at] = std::min(low[at],low[to]);        //happens on callback and here happens the propogation of low link values
        if(ids[at] < low[to]){
          bridges.push_back(at);
          bridges.push_back(to);
        }
      }
      else{
        low [at] = std::min(low[at],ids[to]);   //when you visit already visited and has lower id than current low link value
      }

    }
    
  }

  void findBridges(){
    for(int i=0; i<numVertices; i++){

      if(!visited[i]) dfs(i,-1);

    }
  }
  // Returns a list of pairs of nodes indicating which nodes form bridges.
  // The returned list is always of even length and indexes (2*i, 2*i+1) form a
  // pair. For example, nodes at indexes (0, 1) are a pair, (2, 3) are another
  // pair, etc...
  void print(){
    for(int i=0;i<bridges.size()/2;i++){
      cout<<"Bridge between node : "<<bridges.at(2*i)<<" and "<<bridges.at(2*i+1)<<endl;
    }

  }

};

int main() {
  Bridge b;
  b.addEdge(0,1);
  b.addEdge(0,2);
  b.addEdge(1,2);
  b.addEdge(2,3);
  b.addEdge(2,5);
  b.addEdge(3,4);
  b.addEdge(5,8);
  b.addEdge(5,6);
  b.addEdge(6,7);
  b.addEdge(7,8);

  b.findBridges();
  b.print();
}