class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int lim = (1 << 10);

        vector<vector<vector<bool>>> dp(
            n, vector<vector<bool>>(m, vector<bool>(lim, false)));

        dp[0][0][grid[0][0]] = true;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                for (int val = 0; val < lim; ++val) {
                    if ((i && dp[i - 1][j][val] == true) ||
                        (j && dp[i][j - 1][val] == true))
                        dp[i][j][val ^ grid[i][j]] = true;
                }
            }
        }

        for (int val = 0; val < lim; ++val) {
            if (dp[n - 1][m - 1][val] == true)
                return val;
        }

        return lim;
    }
};
