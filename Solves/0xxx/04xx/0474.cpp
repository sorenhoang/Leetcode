#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int res = 0;
        for (string str : strs)
        {
            auto cnts = count(str);
            for (int i = m; i >= 0; --i)
            {
                for (int j = n; j >= 0; --j)
                {
                    if (i >= cnts[0] && j >= cnts[1])
                    {
                        dp[i][j] = max(dp[i][j], dp[i - cnts[0]][j - cnts[1]] + 1);
                        res = max(res, dp[i][j]);
                    }
                }
            }
        }
        return res;
    }

    vector<int> count(string str)
    {
        int cnt0 = 0, cnt1 = 0;
        for (auto c : str)
        {
            cnt0 += c == '0';
            cnt1 += c == '1';
        }
        return vector<int>{cnt0, cnt1};
    }
};

int main()
{
    // Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
    vector<string> strs{"10", "0001", "111001", "1", "0"};
    cout << Solution().findMaxForm(strs, 5, 3) << endl;
    return 0;
}