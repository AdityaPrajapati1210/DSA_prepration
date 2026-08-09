#include <iostream>
#include <vector>
using namespace std;

int count = 0;
int knapsack(vector<int> val, vector<int> wt, int w, int n, vector<vector<int>> &dp)
{
    count++;
    if (w == 0 || n == 0)
    {
        return 0;
    }
    if (dp[n][w] != -1)
    {
        return dp[n][w];
    }


    int itemwt = wt[n - 1];
    int itemval = val[n - 1];

    if (itemwt <= w)
    {
        // include
        int ans1 = knapsack(val, wt, w - itemwt, n - 1, dp) + itemval;
        // excludde
        int ans2 = knapsack(val, wt, w, n - 1, dp);

        return dp[n][w] = max(ans1, ans2);
    }
    else
    {
        // exclude
        return dp[n][w] = knapsack(val, wt, w, n - 1, dp);
    }
}

int main()
{
    vector<int> val = {20, 12, 5, 50, 10};
    vector<int> wt = {4, 2, 1, 3, 4};
    int w = 7;
    int n = 5;
    vector<vector<int>> dp(n + 1, vector<int>(w + 1, -1));

    cout << knapsack(val, wt, w, n, dp) << endl;
    cout << "count  : " << count << endl;
}