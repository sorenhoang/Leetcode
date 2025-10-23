#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkPartitioning(string s)
    {
        int n = s.size();
        bool dp[n + 3][n + 3];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; ++i)
        {
            dp[i][i] = true;
            dp[i][i - 1] = true;
        }
        for (int i = n; i >= 1; --i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                if (s[i - 1] == s[j - 1] && dp[i + 1][j - 1])
                {
                    dp[i][j] = true;
                }
            }
        }

        for (int i = 1; i <= n - 2; ++i)
        {
            for (int j = i + 1; j <= n - 1; ++j)
            {
                if (dp[1][i] && dp[i + 1][j] && dp[j + 1][n])
                {
                    return true;
                }
            }
        }
        return false;
    }
};