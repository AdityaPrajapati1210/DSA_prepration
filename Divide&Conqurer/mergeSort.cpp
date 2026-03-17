#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int> &arr, int st, int mid, int end){

    vector<int> temp;

    int i = st;
    int j = mid + 1;

    while(i <= mid && j <= end){

        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
        }
    }
    
    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= end){
        temp.push_back(arr[j]);
        j++;
    }

    int k = 0;
    for(int i = st; i <= end; i++){
        arr[i] = temp[k++];
    }
}


void mergeSort(vector<int> &arr,int st ,int end){
    // base case
    if(end - st == 0 || st > end){
        return;
    }
    int mid = st + (end - st)/2;

    mergeSort(arr ,st , mid);
    mergeSort(arr , mid+1,end);

    merge(arr , st,mid ,end);
}



int main(){
    vector<int>nums = {4,5,196,27,74,32,98,0,54,5464,13,68,1,64,554,64,89,};
    int end= nums.size()-1;
    int st = 0;
    mergeSort(nums,st,end);

    for(int i=0;i<nums.size();i++){
        cout << nums[i] <<" ";
    }
}