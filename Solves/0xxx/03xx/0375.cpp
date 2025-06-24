#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMoneyAmount(int n)
    {
        vector<vector<int>> dp(n + 3, vector<int>(n + 3, 0));
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                dp[i][j] = INT_MAX; // Initialize to a large value
            }
        }

        for (int i = 1; i <= n; ++i)
        {
            dp[i][i] = 0;     // No cost if only one number
            dp[i][i - 1] = 0; // No cost if no numbers
        }

        for (int len = 2; len <= n; ++len)
        {
            for (int i = n - 1; i >= 1; --i)
            {
                int j = i + len - 1;
                if (j > n)
                    continue; // Ensure j does not exceed n
                for (int k = i; k <= j; ++k)
                {
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
                }
            }
        }
        return dp[1][n];
    }
};
int main()
{
    Solution sol;
    // Example usage:
    cout << sol.getMoneyAmount(10) << endl; // Output: 16
    return 0;
}