#include<iostream>
using namespace std;


bool sorted(int *arr,int i,int n){
    if(i >= n) return true;
    if(arr[i] > arr[i+1]) return false;
    return sorted(arr ,i+1,n);
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    cout << sorted(arr , 0,9)<< endl;;
}