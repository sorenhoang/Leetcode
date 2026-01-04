#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countCoveredBuildings(int n, vector<vector<int>> &buildings)
    {
        vector<vector<int>> col(n+1, vector<int>());
        vector<vector<int>> row(n+1, vector<int>());    

        for (const auto &building : buildings)
        {
            int r = building[0];
            int c = building[1];
            row[r].push_back(c);
            col[c].push_back(r);
        }

        for(int i=1;i<=n;++i)
        {
            sort(row[i].begin(), row[i].end());
            sort(col[i].begin(), col[i].end());
        }   
        int covered_count = 0;
        for (const auto &building : buildings)
        {
            int r = building[0];
            int c = building[1];
            int lr = lower_bound(row[r].begin(), row[r].end(), c) - row[r].begin();
            int lc = lower_bound(col[c].begin(), col[c].end(), r) - col[c].begin();
            if (lr > 0 && lr < row[r].size() - 1 && lc > 0 && lc < col[c].size() - 1)
            {
                covered_count++;
            }
        }
        return covered_count;
    }
};

int main()
{
    // Input: n = 3, buildings = [[1,2],[2,2],[3,2],[2,1],[2,3]]
    Solution sol;
    vector<vector<int>> buildings = {{1, 2}, {2, 2}, {3, 2}, {2, 1}, {2, 3}};
    int n = 3;
    int ans = sol.countCoveredBuildings(n, buildings);
    cout << ans << endl;

    return 0;
}