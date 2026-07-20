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
    };


    void addEdge(int u , int v){
        l[u].push_back(v);
    };

    void print(){
        for(int i=0;i<V;i++){
            cout << i <<" -> ";
            for(auto neb : l[i]){
                cout << neb << " ";
            }
            cout <<endl;
        }
    }

    void helper(int src,int des,vector<string>&ans,string &path,vector<bool>&vis){
        vis[src] = true;
        path += to_string(src);
        if(src == des){
            ans.push_back(path);
            return;
        }
        list<int> neb = l[src];
        for(auto i : neb){
            if(!vis[i]){
                helper(i,des,ans,path,vis);
                path.pop_back();
                vis[i] = false;
            }
        }
    }

    vector<string> findPath(int src , int des){
        vector<string> ans;
        string path = "";
        vector<bool>vis(V,false);

        helper(src,des,ans,path,vis);
        return ans;
    }
};

int main(){
    Graph gh(6);
    gh.addEdge(5,0);
    gh.addEdge(5,2);
    gh.addEdge(5,3);
    gh.addEdge(0,3);
    gh.addEdge(2,3);
    gh.addEdge(4,0);
    gh.addEdge(4,1);
    gh.addEdge(3,1);

    // gh.print();


    vector<string>ans = gh.findPath(5,1);

    for(auto i : ans){
        for(auto j : i){
            cout << j <<" ";
        }
        cout << endl;
    }
}

