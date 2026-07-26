#include<iostream>
#include<vector>
#include<list>
#include<queue>
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


    int prims(int src){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push(make_pair(0,src));
        vector<bool>set(V,false);
        // set[src] = true;ṇ
        int wgt =0 ;


        while(!pq.empty()){
            int u = pq.top().second;
            int wt = pq.top().first;
            pq.pop();
            if(!set[u]){
                set[u] = true;
                wgt+=wt;

                for(pair<int,int>e : l[u]){
                    if(!set[e.first]){
                        pq.push(make_pair(e.second,e.first));
                    }
                }
            }
        }

        return wgt;
    }
    

};

int main(){
   Graph graph(6);

    graph.addEdge(0,1,4);
    // graph.addEdge(1,0,4);

    graph.addEdge(0,2,3);
    // graph.addEdge(2,0,3);

    graph.addEdge(1,2,1);
    // graph.addEdge(2,1,1);

    graph.addEdge(1,3,2);
    // graph.addEdge(3,1,2);

    graph.addEdge(2,3,4);
    // graph.addEdge(3,2,4);

    graph.addEdge(3,4,2);
    // graph.addEdge(4,3,2);

    graph.addEdge(4,5,6);
    // graph.addEdge(5,4,6);

    graph.addEdge(2,5,5);
    // graph.addEdge(5,2,5);
    // graph.print();
    cout<<graph.prims(0)<<endl;
}