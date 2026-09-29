class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        if (grid[0][0] == ')')
            return false;

        int m = grid.size();
        int n = grid[0].size();
        int lim = n + m + 1;

        vector<vector<vector<bool>>> dp(
            m + 1, vector<vector<bool>>(n + 1, vector<bool>(lim + 1, false)));

        dp[1][1][1] = true;

        for(int i = 1; i <= m; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                int offset = grid[i-1][j-1] == '(' ? 1 : -1;
                for(int val = 0; val <= lim; ++ val)
                {
                    int newVal = val + offset;
                    if(newVal < 0 || newVal >= lim) continue;
                    if(i > 1 && dp[i-1][j][val]) dp[i][j][newVal] = true;
                    if(j > 1 && dp[i][j-1][val]) dp[i][j][newVal] = true;   
                }
            }
        }

        return dp[m][n][0];
    }
};