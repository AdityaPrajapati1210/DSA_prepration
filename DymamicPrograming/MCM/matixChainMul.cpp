#include<iostream>
#include<vector>
using namespace std;


int helper(vector<int>arr, int i, int j){
    if(i == j) return 0;
    int ans= INT16_MAX;

    for(int k=i;k<j;k++){
        int cost1 = helper(arr,i , k);
        int cost2 = helper(arr,k+1,j);
        int currCost = cost1 + cost2 + arr[i-1]*arr[k]*arr[j];
        ans = min(ans,currCost);
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,3};
    cout <<helper(arr,1,arr.size()-1);
}