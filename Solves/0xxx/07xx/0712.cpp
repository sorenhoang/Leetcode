class Solution
{
public:
    int minimumDeleteSum(string s1, string s2)
    {
        if (s2.length() > s1.length())
        {
            swap(s1, s2);
        }

        int n = s1.length();
        int m = s2.length();
        vector<int> dp(m + 1, 0);

        for (int j = 1; j <= m; ++j)
        {
            dp[j] = dp[j - 1] + s2[j - 1];
        }

        for (int i = 1; i <= n; ++i)
        {
            int prev_diag = dp[0];

            dp[0] += s1[i - 1];

            for (int j = 1; j <= m; ++j)
            {
                int temp = dp[j];

                if (s1[i - 1] == s2[j - 1])
                {
                    dp[j] = prev_diag;
                }
                else
                {
                    dp[j] = min(
                        dp[j] + s1[i - 1],
                        dp[j - 1] + s2[j - 1]);
                }
                prev_diag = temp;
            }
        }

        return dp[m];
    }
};