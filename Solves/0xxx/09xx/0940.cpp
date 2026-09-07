class Solution {
public:
    int distinctSubseqII(string s) {
        int n = s.size();
        int MOD = 1e9 + 7;
        vector<int> dp(n + 1, 0);
        vector<int> lastIdx(26, -1);

        for (int i = 1; i <= n; ++i) {
            int c = (s[i - 1] - 'a');
            if (lastIdx[c] == -1) {
                dp[i] = (dp[i - 1] * 2 + 1) % MOD;
            } else {
                dp[i] = (dp[i - 1] * 2 % MOD - dp[lastIdx[c] - 1] + MOD) % MOD;
            }
            lastIdx[c] = i;
        }

        return dp[n];
    }
};