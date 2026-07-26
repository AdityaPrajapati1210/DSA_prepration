#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Edge {
    public:
    int v;
    int wt;

    Edge(int v,int wt){
        this->v = v;
        this->wt = wt;
    }
};


void bellmanFord(int src,vector<vector<Edge>>graph,int V,int des){
    vector<int>dist(V,INT16_MAX);
    dist[src]=0;

    for(int i=0;i<V-1;i++){
        for(int u=0;u<graph.size();u++){
            for(Edge  v : graph[u]){
                if(dist[v.v] > dist[u] + v.wt){
                    dist[v.v] = dist[u] + v.wt;
                }
            }
        }
    }

    for(int i : dist){
        cout << i << " ";
    }

    cout <<endl<<"sortest distance from "<< src << " to "<< des <<" is "<<dist[des]<<endl;
}


int main(){
    vector<vector<Edge>>graph(4);   

    graph[0].push_back(Edge(1,5));
    // graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(2,4));
    // graph[1].push_back(Edge(0,2));
    // graph[1].push_back(Edge(3,7));

    graph[2].push_back(Edge(3,3));

    // graph[3].push_back(Edge(5,1));

    // graph[4].push_back(Edge(3,2));
    // graph[4].push_back(Edge(2,5));


    bellmanFord(0,graph,4,3);
}