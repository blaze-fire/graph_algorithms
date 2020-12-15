#include <iostream>
#include <vector>

using namespace std;

static const int numVertices = 10;


void addEdges(int u, int v, vector<int> g[]){
  g[u].push_back(v);
}

void dfs(int current, bool visited[], vector<int> g[]){
    visited[current] = true;

    for(auto itr = g[current].begin(); itr<g[current].end(); itr++){
        cout<<*itr<<" , ";
    }
    cout<<endl;

}

void Connected_Components(vector<int> g[]){
    bool visited[numVertices] =  {false};

    for (int i = 0; i<numVertices; i++){
        if(!visited[i]){                      //Traverse only unvisited nodes
            dfs(i,visited,g);
        }
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
    Connected_Components(g);
    return 0;
}