#include <iostream>
#include <vector>
using namespace std;

int MaxProfit(vector<int> &price, vector<int> &len, int rodLen, vector<vector<int>> &dp)
{
    for (int i = 1; i <= len.size(); i++)
    {
        for (int j = 1; j <= rodLen; j++)
        {
            if (len[i-1] <= j)
                dp[i][j] = max(price[i-1] + dp[i][j - len[i-1]], dp[i-1][j]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[len.size()][rodLen];
}

int main()
{
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    vector<int> len = {1, 2, 3, 4, 5, 6, 7, 8};
    int rodLen = 8;
    vector<vector<int>> dp(len.size() + 1, vector<int>(rodLen + 1, 0));

    cout << MaxProfit(price, len, rodLen, dp);
}