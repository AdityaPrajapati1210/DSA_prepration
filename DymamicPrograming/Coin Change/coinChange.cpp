#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, 0));

    // Amount 0 ko banane ka 1 way hai
    for (int i = 0; i < coins.size(); i++)
    {
        dp[i][0] = 1;
    }

    // Sirf coin 1 use karke har amount ban sakta hai
    for (int j = 1; j <= amount; j++)
    {
        dp[0][j] = 1;
    }

    // DP
    for (int i = 1; i < coins.size(); i++)
    {
        for (int j = 1; j <= amount; j++)
        {
            if (coins[i] <= j)
            {
                // Current coin ko use karna
                // + current coin ko skip karna
                dp[i][j] = dp[i][j - coins[i]] + dp[i - 1][j];
            }
            else
            {
                // Current coin use nahi kar sakte
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[coins.size() - 1][amount] << endl;

    return 0;
}