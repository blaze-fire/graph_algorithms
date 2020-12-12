#include <iostream>
#include<array>
#include<vector>
#include <stack>

using namespace std;


class tarjans{
  const static int numVertices =10;                 // #vertices
  vector <int> g[numVertices];                      // adjacency list to store edges u and v
  const int UNVISITED = -1;                         // to mark nodes unvisited
  int id = 0, sccCount =0;                          // to maintain record of count of strongly connected components
  std::array <int ,numVertices> ids,low;            // ids and low link arrays
  bool onStack[numVertices] = {false};              // to check whether node on stack or not
  stack <int> s;                                    // stack to store nodes

  public:
  void addEdge(int u, int v){
    g[u].push_back(v);
  }
  void dfs(int at){
    s.push(at);
    onStack[at]=true;
    ids[at] = low[at] = id++;

    //# Visit all neighbours & min low-link on callback 
    for(int i=0;i<numVertices; i++)
      for(auto to : g[i]){
        if(ids[to] == UNVISITED) dfs(to);

        if(onStack[to]) low[at] = std::min(low[at],low[to]);
      }

    //# After having visited all the neighbours of ‘at’   
    //# if we're at the start of a SCC empty the seen   
    //# empty stack until we’re back to the start of the SCC
    if(ids[at] == low[at]){
      while(!s.empty()){
        int node = s.top();
        s.pop();
        onStack[node] =false;
        low[node] = ids[at];
        if(node == at) break;
      }
      sccCount++;
    }
  }

  void findSccs(){
    low.fill(0);

    for(int i=0; i<numVertices; i++) ids.fill(UNVISITED);
      for(int i=0; i<numVertices; i++)
        if(ids[i] == UNVISITED){
          dfs(i);
        }
  }
  void print(){
    for(int i=0;i<low.size();i++){
      cout<<low[i]<<" ";
    }
    cout<<endl<<"# strongly connected components : "<<sccCount<<endl;
  }

};

int main() {
  tarjans t;
  t.addEdge( 6,0 );
  t.addEdge( 6,2 );
  t.addEdge( 3,4 );
  t.addEdge( 6,4 );
  t.addEdge( 2,0 );
  t.addEdge( 0,1 );
  t.addEdge( 4,5 );
  t.addEdge( 5,6 );
  t.addEdge( 3,7 );
  t.addEdge( 7,5 );
  t.addEdge( 1,2 );
  t.addEdge( 7,3 );
  t.addEdge( 5,0 );
  
  t.findSccs();
  t.print();
}