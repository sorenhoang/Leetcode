#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int n = word1.size();
        int m = word2.size();
        int dp[n + 1][m + 1];
        for (int i = 0; i <= n; i++)
            dp[i][0] = i;
        for (int j = 0; j <= m; j++)
            dp[0][j] = j;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                dp[i][j] = (word1[i - 1] == word2[j - 1]) ? dp[i - 1][j - 1] : min(dp[i - 1][j], dp[i][j - 1]) + 1;
            }
        }
        return dp[n][m];
    }
};

int main()
{
    // Input: word1 = "leetcode", word2 = "etco"
    // Output: 4
    Solution sol;
    string word1 = "leetcode";
    string word2 = "etco";
    cout << sol.minDistance(word1, word2) << endl;
    return 0;
}