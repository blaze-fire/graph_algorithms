#include <iostream>
#include <vector>
#include <queue>
#include <array>

using namespace std;

typedef pair<int,int> Pair;                                     // First = Weight & Second = Vertex

class eagerPrims{
  const static int numEdges=10;
  int m = numEdges-1, mstcost=0;
  int edgeCount;                      //to make sure the tree spans the whole graph
  vector <Pair> g[numEdges];
  priority_queue<Pair,vector<Pair>,std::greater<Pair>> ipq;
  bool visited[numEdges] = {false};

  public:

  void addEdge(int u,int wt, int v){
    g[u].push_back(make_pair(wt,v));                
    g[v].push_back(make_pair(wt,u));                    // do this because undirected graph
  }

  void PrimsAlgo(int source){
    Pair info;
    ipq.push(make_pair(0,source));          
    while(!ipq.empty()){
      info = ipq.top();                                 // Use to get minimum weight
      source = info.second;                             // get the vertex
      ipq.pop();                                        // Pop before checking for cycles
      if(visited[source]) continue;                     // Check for cycle

      visited[source] = true;                           // Else, mark the vertex so that we won't have to visit it again
      cout << "Mark vertex " << info.second << " and add weight " << info.first << endl;
      mstcost +=info.first;

      for(auto itr = g[source].begin(); itr!=g[source].end(); itr++){               // Visit all children
        if(!visited[itr->second]){
          ipq.push(make_pair(itr->first, itr->second));                             // Push vertex and weight onto Priority Queue
        }
      } 
    }

    cout << "Minimum cost to connect all vertices : " << mstcost << endl;
  }

};

int main() {
  int source =0;
  eagerPrims P;
  P.addEdge(0,1,1);
  P.addEdge(0,2,3);
  P.addEdge(1,4,2);
  P.addEdge(1,3,3);
  P.addEdge(2,5,3);
  P.PrimsAlgo(source);
  return 0;
}