#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    public:
    int V;
    list<pair<int,int>> *l;

    Graph(int V){
        this->V = V;
        l = new list<pair<int,int>> [V];
    }

    void addEdge(int u,int v,int wt){
        l[u].push_back(make_pair(v,wt));
        l[v].push_back(make_pair(u,wt));
    }

    void print(){
        for(int i=0;i<V;i++){
            cout << i <<"->";
            for(auto it : l[i]){
                cout << it.first << " ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph graph(5);
    graph.addEdge(0,1,5);
    graph.addEdge(1,2,1);
    graph.addEdge(1,3,3);
    graph.addEdge(2,3,1);
    graph.addEdge(2,4,2);
    graph.print();
}