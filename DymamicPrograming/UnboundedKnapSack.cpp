#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int helper(vector<int> &value, vector<int> &weight, int w, int n, vector<vector<int>> &dp)
{

    if (n >= value.size() || w == 0)
        return 0;

    if (dp[n][w] != -1)
        return dp[n][w];

        
        // Take
        int take = 0;
        
        if (w >= weight[n])
        {
            take = value[n] + helper(value, weight, w - weight[n], n, dp);
        }
        
        // Don't take
        int notTake = helper(value, weight, w, n + 1, dp);

    return dp[n][w] = max(take, notTake);
}

int main()
{

    vector<int> value = {15, 14, 10, 45, 30};
    vector<int> weight = {2, 5, 1, 3, 4};

    int w = 7;

    vector<vector<int>> dp(
        value.size(),
        vector<int>(w + 1, -1));

    cout << helper(value, weight, w, 0, dp);
}