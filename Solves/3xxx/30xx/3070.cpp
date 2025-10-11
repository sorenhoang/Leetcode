#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countSubmatrices(vector<vector<int>> &grid, int k)
    {
        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        vector<vector<int>> presum(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                presum[i][j] = presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1] + grid[i - 1][j - 1];
                if (presum[i][j] <= k)
                    res++;
            }
        }
        return res;
    }
};

int main()
{
    //[[7,2,9],[1,5,0],[2,6,6]], k = 20
    Solution sol;
    vector<vector<int>> grid = {{7, 2, 9}, {1, 5, 0}, {2, 6, 6}};
    int k = 20;
    cout << sol.countSubmatrices(grid, k) << endl;
    return 0;
}