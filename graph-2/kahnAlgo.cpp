#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph
{
public:
    int V;
    list<int> *l;

    Graph(int V)
    {
        this->V = V;
        l = new list<int>[V];
    };

    void addEdge(int u, int v)
    {
        l[u].push_back(v);
    };

    void print()
    {
        for (int i = 0; i < V; i++)
        {
            cout << i << " -> ";
            for (auto neb : l[i])
            {
                cout << neb << " ";
            }
            cout << endl;
        }
    }


    void calindeg(vector<int>&indeg){
        for(int i=0;i<V;i++){
            list<int>neb = l[i];
            for(int v : neb){
                indeg[v]++;
            }
        }
    }

    bool topelogicalSorting(){
        // kaha's ALgorihtm
        vector<int>indeg(V,0);
        queue<int>q;

        calindeg(indeg);

        for(int i=0;i<V;i++){
            if(indeg[i] == 0){
                q.push(i);
                // cout<<i<<" ";
            }
        }
        int visited = 0;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            visited++;

            list<int>neb = l[curr];
            for(auto v : neb){
                indeg[v]--;
                if(indeg[v] == 0){
                    q.push(v);
                    // cout <<v << " ";
                }
            }
        }
        return visited != V;
    }
   
};

int main()
{
    Graph gh(4);
    gh.addEdge(0, 2);
    gh.addEdge(2,1);
    // gh.addEdge(5, 3);
    // gh.addEdge(0, 3);ṇ
    gh.addEdge(1, 3);
    gh.addEdge(3, 2);
    // gh.addEdge(4, 1);
    // gh.addEdge(3, 1);
    if(gh.topelogicalSorting()){
        cout<<"has Cycle";
    }else{
        cout<<"Not cylce";
    }

    // gh.print();
}
