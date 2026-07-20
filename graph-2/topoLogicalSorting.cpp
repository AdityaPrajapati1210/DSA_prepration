#include <iostream>
#include <vector>
#include <list>
#include <stack>
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

    void topelogicalSorting(int src, stack<int> &s, vector<bool> &vis)
    {
        vis[src] = true;

        list<int> neb = l[src];
        for (auto i : neb)
        {
            if (!vis[i])
            {
                topelogicalSorting(i, s, vis);
            }
        }
        s.push(src);
    }
};

int main()
{
    Graph gh(6);
    gh.addEdge(5, 0);
    gh.addEdge(5, 2);
    gh.addEdge(5, 3);
    gh.addEdge(0, 3);
    gh.addEdge(2, 3);
    gh.addEdge(4, 0);
    gh.addEdge(4, 1);
    gh.addEdge(3, 1);

    // gh.print();

    stack<int> s;
    vector<bool> vis(6, false);
    for (int i = 0; i < 6; i++)
    {
        if (!vis[i])
        {
            gh.topelogicalSorting(i, s, vis);
        }
    }

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
}
