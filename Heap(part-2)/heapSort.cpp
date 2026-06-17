#include<iostream>
#include<vector>
using namespace std;


void heapify(vector<int>vec, int i,int n){
    int l = 2*i+1;
    int r = 2*i+2;
    int maxI = i;

    if(l >= 0 && vec[l] > vec[maxI]){
        maxI =l;
    }
    if(r >= 0 && vec[r] > vec[maxI]){
        maxI =r;
    }
    swap(vec[maxI] ,  vec[i]);
    if(maxI != i){
        heapify(vec,maxI,n);
    }
}

void heapSort(vector<int>vec, int n){

    for(int i = (n/2)-1; i>=0;i--){
        heapify(vec,i,n);
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