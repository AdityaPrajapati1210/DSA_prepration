#include<iostream>
#include<vector>
using namespace std;

class Heap{
    public:
    vector<int>vec;

    // void push(int val){
    //     int n = vec.size();
    //     if(n == 0){
    //         vec.push_back(val);
    //     }else{
    //         vec.push_back(val);
    //         int child = vec.size()-1;
    //         int parent = (child -1)/2;
    //         while(child > 0 && parent >= 0 && vec[child] > vec[parent]){
    //             swap(vec[child] , vec[parent]);
    //             child = parent;
    //             parent = (child -1)/2;
    //         }
    //     }
    // }

    void push(int val){
        int n = vec.size();
        if(n == 0){
            vec.push_back(val);
        }else{
            vec.push_back(val);
            int child = n-1;
            int parent = (child -1)/2;
            while(child >=0 && parent >= 0 && vec[child] > vec[parent]){
                swap(vec[child],vec[parent]);
                child = parent;
                parent = (child-1)/2;
            }
        }
    }

    void heapify(int i){
        int child1 = 2 *i +1;
        int child2 = 2 *i +2;

        int maxI = i;

        if(child1 < vec.size() && vec[child1] > vec[maxI]){
            maxI = child1;
        }
        if(child2 < vec.size() && vec[child2] > vec[maxI]){
            maxI = child2;
        }

        swap(vec[maxI] , vec[i]);
        if(maxI != i){
            heapify(maxI);
        }
    };

    void pop(){
        int n = vec.size();
        // step-1  swap the parent/root with the last element
        swap(vec[0],vec[n-1]);
        // step-2 delete the last node
        vec.pop_back();
        // step -3 fix the heap using heapify function
        heapify(0);
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
    h.push(40);
    h.push(40);
    h.push(40);
    h.push(40);
    h.print();
    h.pop();
    h.pop();
    h.pop();
    h.pop();
    h.pop();
    h.pop();
    h.pop();
    h.pop();
    h.print();


}
