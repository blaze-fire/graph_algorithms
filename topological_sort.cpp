#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class topological{
    static const int numVertices=6;
    int source;
    vector <bool> VisitedVertex(numVertices,false);
    vector <int> indegree(numVertices,0);
    vector <int> T;
    vector <int> adjlist(numVertices);

    public:
    void addEdge(int u, int v){
        adjlist[u].push_back(v);
    }

    void topological_sort(){
        queue <int> q;
        int v;

        for(int i=0;i<numVertices;i++){
            for(auto itr = adjlist[i].begin(); itr != adjlist[i].end();itr++){
                indegree.at(*itr)++;
            }
        }

        for(int i=0; i<numVertices; i++){
            if(indegree.at(i) == 0){
                source = i;
                q.push(source);
                VisitedVertex.at(source)  true;
                break;
            }
        }

        while (!q.empty()){
            v = q.front();
            q.pop();
            T.push_back(v);

            for(auto itr = adjlist[v].begin();itr != adjlist[v].end();itr++){
                if(!VisitedVertex.at(*itr)){
                    indegree.at(*itr)--;
                    if(indegree.at(*itr)==0){
                        q.push(*itr);
                        VisitedVertex.at(*itr)=true;
                    }
                }

            }
        }


    }

    
};

int main(){
    topological t;
    t.addEdge(0,1);
    t.addEdge(0,3);
    t.addEdge(1,2);
    t.addEdge(1,3);
    t.addEdge(2,3);
    t.addEdge(2,4);
    t.addEdge(2,5);
    t.addEdge(3,4);
    t.addEdge(3,5);
    t.addEdge(4,5);
    t.topological_sort();

    return 0;
}