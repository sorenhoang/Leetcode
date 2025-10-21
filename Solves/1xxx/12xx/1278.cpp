class Solution
{
public:
    int n;
    vector<vector<int>> memo;
    vector<vector<int>> dp;

    int excCount(string &s, int start, int end)
    {
        if (start >= end)
            return 0;
        if (memo[start][end] != -1)
            return memo[start][end];
        return memo[start][end] = (s[start] != s[end]) + excCount(s, start + 1, end - 1);
    }

    int sol(string &s, int k, int ind, int count)
    {
        if (ind == n)
            return 0;
        if (dp[ind][count] != -1)
            return dp[ind][count];
        int ans = 1e9;
        if (count == k - 1)
            return excCount(s, ind, n - 1);
        for (int i = ind; i < n - (k - count - 1); i++)
        {
            ans = min(ans, excCount(s, ind, i) + sol(s, k, i + 1, count + 1));
        }
        return dp[ind][count] = ans;
    }

    int palindromePartition(string s, int k)
    {
        n = s.size();
        dp.resize(n + 1, vector<int>(k + 1, -1));
        memo.resize(n + 1, vector<int>(n + 1, -1));
        return sol(s, k, 0, 0);
    }
};