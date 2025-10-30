#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> fallingSquares(vector<vector<int>> &positions)
    {
        vector<int> res;
        int curHeight = 0;
        int n = positions.size();
        vector<vector<int>> heights(n, vector<int>(3, 0));
        for (int i = 0; i < n; ++i)
        {
            int maxHeight = positions[i][1];
            for (int j = 0; j < i; ++j)
            {
                if (checkOverlap(positions[i], positions[j]))
                {
                    maxHeight = max(maxHeight, heights[j][2] + positions[i][1]);
                }
            }

            heights[i][0] = positions[i][0];
            heights[i][1] = positions[i][1] + positions[i][0];
            heights[i][2] = maxHeight;
            res.push_back(max(curHeight, maxHeight));
            curHeight = res.back();
        }

        return res;
    }

    bool checkOverlap(vector<int> &square1, vector<int> &square2)
    {
        if (square1[0] >= square2[0] + square2[1] || square2[0] >= square1[0] + square1[1])
        {
            return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> positions = {{1, 2}, {2, 3}, {6, 1}};
    vector<int> result = sol.fallingSquares(positions);
    for (int height : result)
    {
        cout << height << " ";
    }
    return 0;
}
// Input: positions = [[1,2],[2,3],[6,1]]