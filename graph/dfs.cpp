#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Graph{
    public:
    int V;
    list<int> *l;

    Graph(int V){
        this->V = V;
        l = new list<int> [V];
    }

    void addEdge(int u,int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void print(){
        for(int i=0;i<V;i++){
            cout << i <<"->";
            for(auto it : l[i]){
                cout << it << " ";
            }
            cout<<endl;
        }
    }

    bool helper(vector<bool>&vis,int node,int parent){

        vis[node] = true;
        // cout<<node<<" ";
        for(int u : l[node]){
            if(!vis[u]){
                if(helper(vis,u,node)){
                    return true;
                };
            }else{
                if(u != parent){
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs() {
    vector<bool> vis(V, false);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (helper(vis, i, -1)) {
                return true;
            }
        }
    }

    return false;
}

};

int main(){
    Graph graph(10);
graph.addEdge(2,9);
graph.addEdge(7,8);
graph.addEdge(5,9);
graph.addEdge(7,2);
graph.addEdge(3,8);
graph.addEdge(2,8);
graph.addEdge(1,6);
graph.addEdge(3,0);
graph.addEdge(7,0);
graph.addEdge(8,5);
    // graph.print();

cout << graph.dfs();
}