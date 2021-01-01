#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int numVertices = 10;

void createAndAddEdge(vector<int> g[], int u, int v){
	g[u].push_back(v);
	g[v].push_back(u);
}


void BFS(vector<int> g[], int source, queue<int> &q, bool visited[]){
	int v;
	q.push(source);
	while(!q.empty()){
		v = q.front();
		q.pop();
		visited[v] = true;
		vector<int>::iterator itr = g[v].begin();
		for(; itr != g[v].end(); itr++){
			if(!visited[*itr]){
				cout<<*itr<<"		";
				
				BFS(g, *itr, q,visited);
			}
		}
	}

}

int main(){
  int source =0;
  queue <int> q;
  bool visited[numVertices] = {false};
  vector<int> adjList[numVertices];
  //vector<bool> visitedVertex(numVertices,false);
  createAndAddEdge(adjList, 0, 1);
  createAndAddEdge(adjList, 0, 2);
  createAndAddEdge(adjList, 1, 5);
  createAndAddEdge(adjList, 2, 3);
  createAndAddEdge(adjList, 2, 4);
  createAndAddEdge(adjList, 3, 3);
  createAndAddEdge(adjList, 4, 4);
  createAndAddEdge(adjList, 5, 5);
  BFS(adjList, source, q, visited);
}