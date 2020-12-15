#include <iostream>
#include <vector>
#include <map>


using namespace std;

class Bellman_Ford{
    const int numVertices = 6;
    map <int,vector<pair<int,int>>> l;

    public:
    void addEdge(int u, int v, int wt){ // storing them as from edge, to edge, weight 
        l[u].push_back(make_pair(v,wt));
    } 

    void Bellman(int source){
        vector <int> dist(100,10000);
        dist.at(source)=0;

        for(int i=0;i<numVertices-1; i++){
            for(auto it:l){
                vector<pair<int,int>> itr = it.second;
                for(auto edge:itr){
                    if((dist.at(it.first) + edge.second) < dist.at(edge.first)){
                        dist.at(edge.first) = (dist.at(it.first) + edge.second);
                    }
                } 
            }
        }

        for(int i=0;i<numVertices-1; i++){
            for(auto it:l){
                vector<pair<int,int>> itr = it.second;
                for(auto edge:itr){
                    if((dist.at(it.first) + edge.second) < dist.at(edge.first)){
                        dist.at(edge.first) = -10000;
                    }
                } 
            }
        }

        
            for(auto it:l){
                cout<<"From : 0 ,to: ";
                vector<pair<int,int>> itr = it.second;
                for(auto edge:itr){
                    cout<<edge.first<<" with dist : "<<dist.at(edge.first);
                }
                cout<<endl;
            } 
            
        

    }
    
};

int main(){
    Bellman_Ford B;
    B.addEdge(0,1,5);
    B.addEdge(1,2,20);
    B.addEdge(2,3,10);
    B.addEdge(1,6,60);
    B.addEdge(6,7,-50);
    B.addEdge(7,8,-10);
    B.Bellman(0);
    return 0;
}