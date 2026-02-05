class Solution
{

public:
    int minCut(string s)
    {
        int n = s.size();
        vector<int> dp(n);
        for (int i = 0; i < n; i++)
            dp[i] = i; // max n cuts;

        for (int i = 0; i < n; i++)
        {
            // odd
            int left = i, right = i;
            while (left >= 0 && right < n && s[left] == s[right])
            {
                if (left == 0)
                    dp[right] = 0;
                else
                    dp[right] = min(dp[left - 1] + 1, dp[right]);
                left--;
                right++;
            }

            // even
            int leftE = i, rightE = i + 1;
            while (leftE >= 0 && rightE < n && s[leftE] == s[rightE])
            {
                if (leftE == 0)
                    dp[rightE] = 0;
                else
                    dp[rightE] = min(dp[leftE - 1] + 1, dp[rightE]);
                leftE--;
                rightE++;
            }
        }
        return dp[n - 1];
    }
};