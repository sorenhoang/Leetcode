class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1);
        dp[0] = 0;
        for(int i = 1; i <= n; ++i)
        {
            dp[i] = dp[i-1] + 1;
            if (i >= 2) dp[i] = min(dp[i], dp[i-2] + 4);
            if (i >= 3) dp[i] = min(dp[i], dp[i-3] + 9);

            dp[i] += costs[i-1];
        }

        return dp[n];
    }
};
