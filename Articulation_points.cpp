#include <iostream>
#include <vector>
#include <array>

using namespace std;

class Articulation{
  const static int numVertices = 9;
  std::array <int,numVertices>  ids,low;
  bool visited[numVertices] = {false}, isArt[numVertices] = {false};
  vector <int> g[numVertices];
  int id = 0,outEdgeCount=0;

  public:

  void addEdge(int u, int v){
    g[u].push_back(v);
    g[v].push_back(u);
  }
  void dfs(int root,int at, int parent){
    if(parent == root)  outEdgeCount++;
    cout<<outEdgeCount<<endl;
    visited[at] = true;
    id++;
    low[at] = ids [at] =id;

    for(auto to : g[at]){
      if(to == parent)  continue;

      if(!visited[to]){
        dfs(root,to,at);
        low[at] = std::min(low[at],low[to]);        //happens on callback and here happens the propogation of low link values
        //# Articulation point found via bridg
        if(ids[at] < low[to])                       //Being explicit here it could be just <=
          isArt[at]=true;
       //# Articulation point found via cycle 
        if(ids[at] == low[to])
          isArt[at] = true;        
      }
      else{
        low [at] = std::min(low[at],ids[to]);   //when you visit already visited and has lower id than current low link value
      }

    }
    
  }

  void findArtPoints(){
    for(int i=0; i<numVertices; i++){

      if(!visited[i]) {
        outEdgeCount = 0;                 //Reset Edge count
        dfs(i,i,-1);
        if(outEdgeCount>1)  isArt[i]=true; 
      }

    }
  }

  void print(){
    for(int i=0;i<numVertices;i++){
      if(isArt[i])  cout<<i<<" , ";
    }

  }

};

int main() {
  Articulation A;
  A.addEdge(0,1);
  A.addEdge(0,2);
  A.addEdge(1,2);
  A.addEdge(2,3);
  A.addEdge(2,5);
  A.addEdge(3,4);
  A.addEdge(5,8);
  A.addEdge(5,6);
  A.addEdge(6,7);
  A.addEdge(7,8);

  A.findArtPoints();
  A.print();
}