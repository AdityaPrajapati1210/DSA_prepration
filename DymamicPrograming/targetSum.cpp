#include <iostream>
#include <vector>
using namespace std;

bool targetSum(vector<int> &nums, int n, int target, vector<vector<int>> &dp)
{

    // Target mil gaya
    if (target == 0)
    {
        return true;
    }

    // Array khatam
    if (n >= nums.size())
    {
        return false;
    }

    // Already calculated
    if (dp[n][target] != -1)
    {
        return dp[n][target];
    }

    // Take
    bool take = false;

    if (target >= nums[n])
    {
        take = targetSum(nums, n + 1,target - nums[n], dp);
    }

    // Don't take
    bool notTake = targetSum(nums, n + 1,target, dp);

    // Store answer
    dp[n][target] = take || notTake;

    return dp[n][target];
}

int main()
{

    vector<int> nums = {2, 3, 7, 8, 10};

    int n = nums.size();
    int target = 11;

    vector<vector<int>> dp(
        n,
        vector<int>(target + 1, -1));

    cout << targetSum(nums, 0, target, dp);
}