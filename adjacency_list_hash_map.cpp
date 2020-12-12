#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Graph{
    unordered_map<string,vector<pair<string,int>>> l;

    public:
    void addEdge(string x,string y, bool bidir, int wt){
        l[x].push_back(make_pair(y,wt));
        if(bidir){
            l[y].push_back(make_pair(x,wt));
        }
    }

    void print(){
        for(auto p :l){
            cout<<"City : "<<p.first<<"->";
            vector<pair<string,int>> nbrs = p.second;
            for(auto nbr:nbrs){
                cout<<nbr.first<<" ,dist: "<<nbr.second<<"  ";
            }
            cout<<endl;
        }
    }

};


int main() {
  Graph G;
  G.addEdge("A","B",true,20);
  G.addEdge("B","D",true,40);
  G.addEdge("A","C",true,10);
  G.addEdge("C","D",true,40);
  G.addEdge("A","D",false,50);
  G.print();
  return 0;
}