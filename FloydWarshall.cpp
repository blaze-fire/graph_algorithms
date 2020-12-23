#include <iostream>

using namespace std;

class floydWarshall{
    static const int size = 4;
    int dp[size][size], next[size][size];
    public:

    void addData(){
        int data;
        for (int i = 0; i < size; i++)
        {
            for(int j=0; j<size; j++){
                cin>>data;
                dp[i][j]=data;
            }
        }
        
    }

    void Algo(){
        for(int i = 0;i<size;i++){
            for(int j=0;j<size;j++){
                next[i][j] = dp[i][j];
            }
        }

        for(int k=0;k<size;k++){
            for(int i = 0;i<size;i++){
                for(int j=0;j<size;j++){
                    next[i][j] = std::min((next[i][k]+next[k][j]),next[i][j]);
                }
            }
        }


    }

    void print(){
        cout<<endl<<endl;
        for(int i=0;i<size; i++){
            for(int j=0; j<size; j++){
                cout<<next[i][j]<<" , ";
            }
            cout<<endl;
        }
    }


};

int main(){
    floydWarshall F;
    F.addData();
    F.Algo();
    F.print();


    return 0;
}