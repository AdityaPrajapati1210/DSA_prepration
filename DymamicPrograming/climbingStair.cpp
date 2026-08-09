#include<iostream>
#include<vector>
using namespace std;


int climbing(int n,vector<int>&dp){
    if(n==0 || n==1){
        return 1;
    }

    if(dp[n] != -1){
        return dp[n];
        cout <<"1";
    }

    return dp[n] = climbing(n-1,dp) + climbing(n-2,dp);
}

int main(){
    int n;
    cout<<"Enter the number you want less than 50 : ";
    cin>>n;
    vector<int>dp(n,-1);
    cout << climbing(n,dp) <<endl;

}