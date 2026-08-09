#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class DisjointSet
{
public:
    int n;
    vector<int> par;
    vector<int> rank;
    int cost =0;

    DisjointSet(int n)
    {

        this->n = n;
        for (int i = 0; i < n; i++)
        {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x)
    {
        if (par[x] == x)
        {
            return x;
        }
        return par[x] = find(par[par[x]]);
    };

    void unionByrank(int a, int b,int wt)
    {
        int A = find(a);
        int B = find(b);
        if(A == B){
            return;
        }
        cout<<"edges ; (" << a <<", "<<b<<", "<<wt<<")"<<endl;
        if (rank[A] == rank[B])
        {
            cost+=wt;
            par[B] = A;
            rank[A]++;
        }
        else if (rank[A] > rank[B])
        {
            cost+=wt;
            par[B] = A;
        }
        else
        {
            cost+=wt;
            par[A] = B;
        }
    }
};

class Edge
{
public:
    int u;
    int v;
    int wt;

    Edge(int u, int v, int wt)
    {
        this->u = u;
        this->v = v;
        this->wt = wt;
    }

    bool operator < (const Edge &obj)const{
        return this->wt < obj.wt;
    }
};

int kruskal(vector<Edge> edges)
{
    int n = edges.size();
    DisjointSet d(n);

    for (int i = 0; i < n; i++){
        d.unionByrank(edges[i].u, edges[i].v,edges[i].wt);
    }

    return d.cost;
}

int main()
{
    vector<Edge> edges;
    edges.push_back(Edge(0, 1, 10));
    edges.push_back(Edge(0, 2, 20));
    edges.push_back(Edge(0, 3, 55));
    edges.push_back(Edge(1, 3, 30));
    edges.push_back(Edge(2, 3, 50));

    sort(edges.begin(),edges.end());

    cout << kruskal(edges) <<endl;
}