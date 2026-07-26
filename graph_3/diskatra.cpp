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


void dijkstra(int src,vector<vector<Edge>>graph,int V,int des){
    vector<int>dist(V,INT16_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>>pq;

    pq.push(make_pair(0,src));
    dist[src]=0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(auto  v : graph[u]){
            if(dist[v.v] > dist[u] + v.wt){
                dist[v.v] = dist[u] + v.wt;
                pq.push(make_pair(dist[v.v],v.v));
            }
        }
    }

    for(int i : dist){
        cout << i << " ";
    }

    cout <<endl<<"sortest distance from "<< src << " to "<< des <<" is "<<dist[des]<<endl;
}


int main(){
    vector<vector<Edge>>graph(6);   

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(2,1));
    graph[1].push_back(Edge(3,7));

    graph[2].push_back(Edge(4,3));

    graph[3].push_back(Edge(5,1));

    graph[4].push_back(Edge(3,2));
    graph[4].push_back(Edge(2,5));


    dijkstra(0,graph,6,5);
}