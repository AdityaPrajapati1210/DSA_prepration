#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph {
    public:
    list<int> *l;
    int V;

    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    };

    void addEdge(int u , int v){
        l[u].push_back(v);
    }

    void print(){
        for(int i=0;i<V;i++){
            cout << i << "->";
            for(auto it : l[i]){
                cout << it << " ";
            }
            cout <<endl;
        }

    }


};

int main(){
    Graph gh(3);
    gh.addEdge(0,1);
    gh.addEdge(1,2);
    gh.addEdge(2,0);
    gh.print();
}

