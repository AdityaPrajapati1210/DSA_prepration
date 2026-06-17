#include<iostream>
#include<vector>
using namespace std;


void heapify(vector<int>&vec, int i,int n){
    int l = 2*i+1;
    int r = 2*i+2;
    int maxI = i;

    if(l < n && vec[l] > vec[maxI]){
        maxI =l;
    }
    if(r < n && vec[r] > vec[maxI]){
        maxI =r;
    }
    if(maxI != i){
        swap(vec[maxI] ,  vec[i]);
        heapify(vec,maxI,n);
    }
}

void heapSort(vector<int>&vec, int n){
    // building max heap
    for(int i = (n/2)-1; i>=0;i--){
        heapify(vec,i,n);
    }


    // sorting
    for(int i = n-1;i>=0;i--){
        swap(vec[0],vec[i]);
        heapify(vec,0,i);
    }
}

int main(){
    vector<int>vec = {1,4,3,5,7,3,2};
    int n = vec.size();
    heapSort(vec , n);
    for(int i=0;i<n;i++){
        cout << vec[i]<<" ";
    }
    cout << endl;
}