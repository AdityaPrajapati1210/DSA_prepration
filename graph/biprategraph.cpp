#include<iostream>
#include<vector>
#include<list>
#include<set>
using namespace std;

class Graph {
    public:
    int V;
    list<int> *l;

    Graph(int V){
        this->V =V;
        l = new list<int> [V];
    }

    void addEdge(int u , int v){
        l[u].push_back(v);
        l[v].push_back(u);
    }


    bool helper(vector<bool>&vis,int src,set<int>&set1,set<int>&set2){
        vis[src] = true;

        for(int i :l[src]){
            if(!vis[i]){
                if(set1.count(src)){
                    set2.insert(i);
                }else if(set2.count(src)){
                    set1.insert(i);
                }
                if(!helper(vis,i,set1,set2)){
                    return false;
                };
            }else{
                if(set1.count(src) && set1.count(i) ||set2.count(src) && set2.count(i)){
                    return false;
                }
            }
        }
        return true;
    }
    
    set<int>set1;
    set<int>set2;
    bool isBiparte(){
        vector<bool>vis(V,false);
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
            set1.insert(i);
                if(!helper(vis,i,set1,set2)){
                    return false;
                }
            }
        }
        return true;
    }

    void printset(){
        cout<<endl;
        for(int i : set1){
            cout << i << " ";
        }
        cout<<endl;
        for(int i : set2){
            cout << i << " ";
        }
        cout<<endl;
    }
};

int main(){
    Graph gh(3);
    gh.addEdge(0,1);
    gh.addEdge(1,2);
    gh.addEdge(2,0);
    // gh.addEdge(3,0);

    if(gh.isBiparte()){
        cout<<"It is an Biprate graph";
    }else{
        cout<<"It is an  not Biprate graph";
    }

    gh.printset();
}