#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph {
    public:
    int V;
    list<int> *l;


    Graph(int V){
        this->V =  V;
        l = new list<int> [V];
    }

    void addEdge(int u, int v){
        l[u].push_back
    }

}