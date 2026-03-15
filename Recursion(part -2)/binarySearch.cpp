#include<iostream>
using namespace std;

int binary(int *arr ,int target, int s ,int e){
    if(s>e) return -1;
    int mid = s + (e - s)/2;
    if(arr[mid] == target){
        return mid;
    }else if(arr[mid] > target){
        return binary(arr,target,s,mid-1);
    }else{
        return binary(arr,target,mid+1,e);
    }
    return -1;
}

int main(){
    int arr[] = {1,2,3,4,5,6,7,8,9};
    cout << binary(arr,7,0,8) << endl;
}