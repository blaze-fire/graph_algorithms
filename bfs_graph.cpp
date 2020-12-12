#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void createAndAddEdge(vector <int> adjlist[],int u, int v){
  adjlist[u].push_back(v);
  adjlist[v].push_back(u);
}

void BFS(vector <int> adjList[], vector<bool> VisitedVertex, int Source){
  queue<int> q;
  int v;
  q.push(Source);
  while(!q.empty()){
    v = q.front();
    VisitedVertex[v]=true;
    q.pop();
    cout<<v<<" ";
    vector<int>::iterator it;
    for(it = adjList[v].begin(); it != adjList[v].end();it++){
      if(!VisitedVertex.at(*it)){
        q.push(*it);
        VisitedVertex.at(*it)=true;
      }
    
    }
  }
  cout<<endl;
}

int main(){
  // Idea is to implement adjacency list as an array of vectors
  const int numVertices = 6;
  int source =0;
  vector<int> adjList[numVertices];
  vector<bool> visitedVertex(numVertices,false);
  createAndAddEdge(adjList, 0, 1);
  createAndAddEdge(adjList, 0, 2);
  createAndAddEdge(adjList, 1, 5);
  createAndAddEdge(adjList, 2, 3);
  createAndAddEdge(adjList, 2, 4);
  createAndAddEdge(adjList, 3, 3);
  createAndAddEdge(adjList, 4, 4);
  createAndAddEdge(adjList, 5, 5);
  BFS(adjList, visitedVertex, source);
}