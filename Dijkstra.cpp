#include <iostream>
#include <queue>
#include <vector>
#include <array>
using namespace std;

typedef pair<int,int> Pair;
static const int numVertices = 6;

void addEdge(vector <Pair> adjList[], int u, int v, int wt ){
  adjList[u].push_back(make_pair(wt,v));
}

void Dijkstra(vector <Pair> adjList[],int source){
  priority_queue <Pair,vector<Pair>,std::greater<Pair>> PQ;
  Pair info;
  PQ.push(make_pair(0,source));
  bool visited[numVertices] = {false};
  std::array <int,100> dist;
  dist.fill(10000);
  dist[source] = 0;
  while(!PQ.empty()){
    info = PQ.top();
    PQ.pop();
    int index = info.second;
    int MinValue = info.first;
    visited[index] = true;
    
    if(dist[index] < MinValue)  continue;    

    auto it = adjList[index].begin();
    for(; it != adjList[index].end(); it++){
      if(visited[it->second])  continue;
      int newDist = dist[index] + it->first;
      if(newDist < dist[it->second]){
        dist[it->second] = newDist; 
        PQ.push(make_pair(newDist, it->second));
      }
    }
  }

  for(int i = 0; i < numVertices; i++){
    cout<<dist[i]<<" , ";
  }

}

int main(){
  vector <Pair> adjList[numVertices];

  addEdge(adjList,0,1,4);
  addEdge(adjList,0,2,1);
  addEdge(adjList,2,1,2);
  addEdge(adjList,2,3,5);
  addEdge(adjList,1,3,1);
  addEdge(adjList,3,4,3);  

  Dijkstra(adjList, 0);

  return 0;
}
