#include <iostream>
#include <list>
#include <vector>
using namespace std;


class Graph{
    static const int V=4;
    //Array of lists
    vector<int> l[V];
    public:

    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void print(){
        // iterate over all vertices

        for(int i=0; i<V; i++){
            cout<<"Vertex "<<i<<"->";
            
            for(auto itr : l[i]){
                cout<<itr<<" , ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(2,3);
    g.addEdge(1,2);

    g.print();
    return 0;
}