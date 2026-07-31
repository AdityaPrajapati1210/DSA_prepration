#include<iostream>
#include<vector>
using namespace std;

class DisjointSet{
    public:
    int n;
    vector<int>par;
    vector<int>rank;

    DisjointSet(int n){
        
        this->n = n;
        for(int  i=0; i<n;i++){
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x){
        if(par[x] == x){
            return x;
        }
        return par[x] = find(par[par[x]]);
    };

    void unionByrank(int a, int b){
        int A = find(a);
        int B = find(b);
        if(rank[A] == rank[B]){
            par[B] = A;
            rank[A]++;
        }else if(rank[A] > rank[B]){
            par[B] = A;
        }else{
            par[A] = B;
        }
    }
};

int main(){
    DisjointSet ds(6);
    ds.unionByrank(0,2);
    ds.unionByrank(5,3);
    ds.unionByrank(0,5);
    cout << ds.find(2) <<endl;
    cout << ds.find(3) <<endl;
    cout << ds.find(4) <<endl;
    cout << ds.find(5) <<endl;
    cout << ds.find(1) <<endl;

}