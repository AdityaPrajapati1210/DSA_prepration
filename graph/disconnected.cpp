#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    public:
    int V;
    list<int>*l;

    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }


    void print(){
        for(int i = 0;i<V;i++){
            cout << i <<" ->";
            for(int it : l[i]){
                cout << it <<" ";
            }
            cout <<endl;
        }
    }

    void helper(vector<bool>&vis,int node){

        if(vis[node]){
            return;
        }

        vis[node] = true;
        cout<<node<<" ";
        for(int u : l[node]){
            if(!vis[u]){
                helper(vis,u);
            }
        }
    }

    void dfs(){
        vector<bool>vis(V,false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                helper(vis,i);
            }
        }
    }


};

int main(){
    Graph graph(10);
    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(2,3);

    // Component 2
    graph.addEdge(4,5);
    graph.addEdge(5,6);
    graph.addEdge(4,6);

    // Component 3
    graph.addEdge(7,8);
    graph.addEdge(8,9);
    // graph.print();

    graph.dfs();
}