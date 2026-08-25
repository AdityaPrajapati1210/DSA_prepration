#include <iostream>
#include <vector>
#include <string>
using namespace std;

int lcs(string &str1, string &str2, int n, int m,
        vector<vector<int>> &dp)
{
    if(n == 0 || m == 0)
        return 0;

    if(dp[n][m] != -1)
        return dp[n][m];

    if(str1[n-1] == str2[m-1])
    {
        return dp[n][m] =
            1 + lcs(str1, str2, n-1, m-1, dp);
    }

    return dp[n][m] = max(
        lcs(str1, str2, n-1, m, dp),
        lcs(str1, str2, n, m-1, dp)
    );
}

int main()
{
    string str1 = "abcdge";
    string str2 = "abedg";

    vector<vector<int>> dp(
        str1.length() + 1,
        vector<int>(str2.length() + 1, -1)
    );

    cout << lcs(str1, str2,
                str1.length(),
                str2.length(),
                dp);
}