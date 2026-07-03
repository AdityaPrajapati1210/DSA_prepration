#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

class Graph{
    public:
    int V;
    list<pair<int,bool>> *l;

    Graph(int V){
        this->V = V;
        l = new list<pair<int,bool>> [V];
    }

    void addEdge(int u,int v){
        l[u].push_back(make_pair(v,false));
        l[v].push_back(make_pair(u,false));
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


    void BFS(){
        queue<int>q;
        q.push(0);
        vector<bool>vis(V,false);
        vis[0] = true;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            cout<< curr <<"->";
            
            for(auto v : l[curr]){
                if(!vis[v.first]){
                    q.push(v.first);
                    vis[v.first] = true;
                }
            }
        }
    }
    

};

int main(){
    Graph graph(5);
    graph.addEdge(0,1);
    graph.addEdge(1,2);
    graph.addEdge(1,3);
    graph.addEdge(2,3);
    graph.addEdge(2,4);
    // graph.print();
    graph.BFS();
}