class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
            int rodLen = price.size();
            vector<vector<int>> dp(price.size() + 1, vector<int>(rodLen + 1, 0));
            for (int i = 1; i <= price.size(); i++)
            {
                for (int j = 1; j <= rodLen; j++)
                {
                    if (i <= j)
                        dp[i][j] = max(price[i-1] + dp[i][j-i], dp[i-1][j]);
                    else
                        dp[i][j] = dp[i-1][j];
                }
            }
            return dp[price.size()][rodLen];
    }
};