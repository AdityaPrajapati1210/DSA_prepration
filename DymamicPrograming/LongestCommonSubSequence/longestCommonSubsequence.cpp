#include<iostream>
#include<vector>
#include<string>
using namespace std;

int MaxLen(string &str1,string &str2,int n,int m,vector<vector<int>>&dp){
    if(m==0 || n ==0){
        return 0;
    }

    if(dp[n][m] != -1) return dp[n][m];
    int take = 0;
    if(str1[n-1] == str2[m-1]){
        take = 1 + MaxLen(str1,str2,n-1,m-1,dp);
    }
    int dontake = max(MaxLen(str1,str2,n-1,m,dp),MaxLen(str1,str2,n,m-1,dp));

    dp[n][m] = max(take,dontake);
    return dp[n][m];
}



int main(){
    string str1 = "abcde";
    string str2 = "abde";
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
    cout << MaxLen(str1,str2,n,m,dp)<<endl;
}