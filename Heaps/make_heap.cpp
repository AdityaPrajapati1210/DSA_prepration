#include<iostream>
#include<vector>
using namespace std;

class Heap{
    public:
    vector<int>vec;

    void push(int val){
        int n = vec.size();
        if(vec.size() == 0){
            vec.push_back(val);
        }else{
            vec.push_back(val);
            int child = n-1;
            int parent = (child -1)/2;
            while(child > 0 && parent >= 0 && vec[child] > vec[parent]){
                swap(vec[child] , vec[parent]);
                child = parent;
                parent = (child -1)/2;
            }
        }
    }

    void pop(){

    }

    int top(){
        return vec[0];
    }

    void print(){
        for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
        cout <<endl;
    }
};

int main(){

    Heap h;
    h.push(10);
    h.push(50);
    h.push(2);
    h.push(4);
    h.push(40);
    h.print();


}
