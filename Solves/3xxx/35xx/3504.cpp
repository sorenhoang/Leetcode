#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int longestPalindrome(string s, string t)
    {
        int n = s.size();
        int m = t.size();
        reverse(t.begin(), t.end());
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        vector<int> leftS = buildLeftPalin(s);
        vector<int> leftT = buildLeftPalin(t);

        s = " " + s;
        t = " " + t;

        int res = 0;

        for (int i = 0; i <= n; ++i)
        {
            for (int j = 0; j <= m; ++j)
            {
                if (s[i] == t[j] && i > 0 && j > 0)
                {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }

                res = max(res, dp[i][j] * 2 + max(i == n ? 0 : leftS[i + 1], j == m ? 0 : leftT[j + 1]));
            }
        }

        return res;
    }

    vector<int> buildLeftPalin(string s)
    {
        int n = s.size();
        vector<int> res(n + 1, 1);
        vector<vector<bool>> palinS(n + 1, vector<bool>(n + 1, false));
        s = " " + s;
        for (int l = n; l >= 1; --l)
        {
            palinS[l][l] = true;
            palinS[l][l - 1] = true;
            for (int r = l + 1; r <= n; ++r)
            {
                if (s[l] == s[r])
                {
                    palinS[l][r] = palinS[l + 1][r - 1];
                }

                if (palinS[l][r])
                    res[l] = r - l + 1;
            }
        }
        return res;
    }
};