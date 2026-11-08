class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> existedRow(m);
        vector<int> existedColumn(n);

        int ans = 0;
        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j])
                {
                    existedRow[i] ++;
                    existedColumn[j] ++;
                }
            }
        }

        for(int i = 0; i < m; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(grid[i][j] && (existedRow[i] > 1 || existedColumn[j] > 1))
                {
                    ans ++;
                }
            }
        }

        return ans;
    }
};
