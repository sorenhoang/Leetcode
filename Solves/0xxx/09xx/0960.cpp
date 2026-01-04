#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        if (strs.size() == 0)
            return 0;

        int n = strs.size();
        int m = strs[0].size();
        int res = max(0, m - 1);

        vector<vector<int>> cnt(m, vector<int>(m, 0));

        for (string str : strs)
        {
            for (int i = 0; i < m; ++i)
            {
                for (int j = i + 1; j < m; ++j)
                {
                    if (str[i] <= str[j])
                    {
                        cnt[i][j]++;
                    }
                }
            }
        }

        vector<int> dp(m, 1);
        for (int j = 1; j < m; ++j)
        {
            for (int i = 0; i < j; ++i)
            {
                if (cnt[i][j] == n)
                {
                    dp[j] = max(dp[j], dp[i] + 1);
                }
            }
            res = min(res, m - dp[j]);
        }

        return res;
    }
};

int main()
{
    // Input: strs = ["babca","bbazb"]
    // Output: 3
    vector<string> strs{"babca", "bbazb"};
    cout << Solution().minDeletionSize(strs) << endl;
    return 0;
}