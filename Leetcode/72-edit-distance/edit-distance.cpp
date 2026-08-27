class Solution {
public:
int MinOpr(string &str1, string &str2, int n, int m, vector<vector<int>> &dp)
{
    if (n == 0)
        return m;
    if (m == 0)
        return n;

    if (dp[n][m] != -1)
        return dp[n][m];

    int same = INT16_MAX;
    int notSame = INT16_MAX;
    if (str1[n - 1] == str2[m - 1])
    {
        same = 0 + MinOpr(str1, str2, n - 1, m - 1, dp);
    }
    else
    {
        notSame = 1 + min(min(MinOpr(str1, str2, n, m - 1, dp), MinOpr(str1, str2, n - 1, m, dp)), MinOpr(str1, str2, n - 1, m - 1, dp));
    }

    return dp[n][m] = min(same, notSame);
}
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return MinOpr(word1,word2,n,m,dp);
    }
};