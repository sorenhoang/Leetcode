#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    string lexicographicallySmallestString(string s)
    {

        int n = s.size();
        s = " " + s; // 1-indexed
        vector<vector<bool>> canRemove(n + 2, vector<bool>(n + 2, false));
        for (int i = 1; i <= n; ++i)
            canRemove[i][i - 1] = true;

        for (int i = n; i >= 1; --i)
        {
            for (int j = i + 1; j <= n; ++j)
            {
                for (int k = i; k < j; ++k)
                {
                    if (canRemove[i][k] && canRemove[k + 1][j])
                    {
                        canRemove[i][j] = true;
                        break;
                    }
                }
                if ((abs(s[i] - s[j]) == 1 || abs(s[i] - s[j]) == 25) && canRemove[i + 1][j - 1])
                    canRemove[i][j] = true;
            }
        }

        vector<string> dp(n + 2);
        dp[n + 1] = "";
        for (int i = n; i >= 1; --i)
        {
            dp[i] = s.substr(i, n - i + 1);
            for (int j = i + 1; j <= n + 1; ++j)
            {
                dp[i] = min(dp[i], (canRemove[i][j - 1] ? "" : s.substr(i, j - i)) + dp[j]);
            }
        }
        return dp[1];

        return "";
    }
};

int main()
{
    string s = "bfpnxqzyimmzadru";
    Solution sol;
    cout << sol.lexicographicallySmallestString(s) << endl;
    return 0;
}