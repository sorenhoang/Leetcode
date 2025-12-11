#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int lim = 1e9;
        vector<vector<int>> height(isWater.size(), vector<int>(isWater[0].size(), lim));
        queue<pair<int, int>> q;
        int n = isWater.size();
        int m = isWater[0].size();
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                if (isWater[i][j] == 1)
                {
                    height[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        while(!q.empty())
        {
            auto id = q.front();
            int x = id.first, y = id.second;
            q.pop();
            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for (const auto &dir : directions)
            {
                int newX = x + dir.first;
                int newY = y + dir.second;
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && height[newX][newY] > height[x][y] + 1)
                {
                    height[newX][newY] = height[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }

        return height;
    }
};

int main()
{
    // isWater = [[0,1],[0,0]]
    vector<vector<int>> isWater = {{0, 1}, {0, 0}};
    Solution sol;
    vector<vector<int>> result = sol.highestPeak(isWater);
    for (const auto &row : result)
    {
        for (const auto &val : row)
        {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}