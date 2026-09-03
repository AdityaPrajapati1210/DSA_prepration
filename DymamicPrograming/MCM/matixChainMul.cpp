#include<iostream>
#include<vector>
using namespace std;


int helper(vector<int>&arr, int i, int j,vector<vector<int>>&dp){
    if(i == j) return 0;

    if(dp[i][j] != -1){
        return dp[i][j];
    }
    int ans= INT16_MAX;

    for(int k=i;k<j;k++){
        int cost1 = helper(arr,i , k,dp);
        int cost2 = helper(arr,k+1,j,dp);
        int currCost = cost1 + cost2 + arr[i-1]*arr[k]*arr[j];
        ans = min(ans,currCost);
    }
    return ans;
}

int main(){
    vector<int> arr = {1,2,3,4,3};
    int  n= arr.size();
    vector<vector<int>>dp(n+1, vector<int>(n+1,-1));
    cout <<helper(arr,1,n-1,dp);
}