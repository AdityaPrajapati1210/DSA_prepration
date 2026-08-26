        #include<iostream>
        #include<vector>
        #include<string>
        using namespace std;


        int main(){
            string str1 = "abcde";
            string str2 = "abcg";
            int n = str1.length();
            int m = str2.length();
            vector<vector<int>>dp(n+1,vector<int>(m+1,0));
            
            int ans= 0;
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if(str1[i-1] == str2[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }else{
                        dp[i][j] = 0;
                    }

                    ans = max(ans,dp[i][j]);
                }
            }

            cout <<ans<<endl;
        }