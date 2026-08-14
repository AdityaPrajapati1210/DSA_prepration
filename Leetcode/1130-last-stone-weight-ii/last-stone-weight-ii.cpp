class Solution {
public:
    bool subset(vector<int>& stones, int n, int target,
                vector<vector<int>>& dp) {

        if (target == 0)
            return true;

        if (n >= stones.size())
            return false;

        if (dp[n][target] != -1)
            return dp[n][target];

        bool take = false;

        if (target >= stones[n]) {
            take = subset(stones, n + 1,
                          target - stones[n], dp);
        }

        bool notTake = subset(stones, n + 1,
                              target, dp);

        return dp[n][target] = take || notTake;
    }


    int lastStoneWeightII(vector<int>& stones) {

        int sum = 0;

        for (int i = 0; i < stones.size(); i++) {
            sum += stones[i];
        }

        int target = sum / 2;

        for (int t = target; t >= 0; t--) {

            vector<vector<int>> dp(
                stones.size(),
                vector<int>(t + 1, -1)
            );

            if (subset(stones, 0, t, dp)) {
                return sum - 2 * t;
            }
        }

        return 0;
    }
};