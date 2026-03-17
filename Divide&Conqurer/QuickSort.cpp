#include<iostream>
using namespace std;


int position(int *arr, int st, int end){
    int i = st-1;
    int j = st;
    while(j < end){
        if(arr[j] < arr[end]){
            swap(arr[++i] , arr[j]);
        }
        j++;
    }
    swap(arr[++i] , arr[end]);
    return i;
}

void Quick(int *arr,int st, int end){
    if(st >= end) return;
    int pivot = position(arr,st,end);    

    Quick(arr, st,pivot-1);
    Quick(arr, pivot+1 ,end);
}

int main(){
    int arr[] = {44,41,6,66,1,2,8,2,9,1,7,3,3,9,2};
    int end = sizeof(arr)/sizeof(int) -1;

    Quick(arr,0,end);

    for(int i=0;i<=end;i++){
        cout << arr[i] <<" ";
    }
}