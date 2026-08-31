#include<iostream>
#include<vector>
using namespace std;

int helper(int n ,vector<int>&dp){
    if(n == 1 || n == 0){
        return dp[n];
    }
    if(dp[n] != -1){
        return dp[n];
    }

    int ans =0;

    for(int i=0;i<n;i++){
        ans+=helper(i,dp) * helper(n-i-1,dp);
    }

    return dp[n] = ans;
}

int main(){
    int n = 6;
    vector<int>dp(n+1,-1);
    dp[0] = 1;
    dp[1] = 1;

    cout << helper(n,dp) <<endl;

}