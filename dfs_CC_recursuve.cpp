  
/**
 * An implementation of a recursive approach to DFS Time Complexity: O(V + E)
 */
#include <iostream>
#include <vector>

using namespace std;

static const int numVertices = 10;

void addEdges(int u, int v, vector<int> g[]){
	g[u].push_back(v);
}

void dfs(int current, vector<int> g[], bool visited[]){
	if(visited[current])	return;

	visited[current] = true;

	vector<int>::iterator itr = g[current].begin();
	for(; itr != g[current].end(); itr++){
		cout<<*itr<<"		";
		dfs(*itr, g, visited);
		//cout<<endl;
	}
	
}

int main(){
	vector<int> g[numVertices];
	addEdges(0,1,g);  
    addEdges(0,3,g);  
    addEdges(1,5,g);
    addEdges(1,2,g);
    addEdges(1,4,g);
    addEdges(2,4,g);
    addEdges(2,3,g);
    bool visited[numVertices] = {false};			
    dfs(0, g, visited);								// Start at node 0
	return 0;
}