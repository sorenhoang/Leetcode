// optimized version 2: only reuse triangle for dp

#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        for (int row = triangle.size() - 1; row > 0; --row)
        {
            for (int col = 0; col < row; ++col)
            {
                triangle[row - 1][col] +=
                    min(triangle[row][col], triangle[row][col + 1]);
            }
        }

        return triangle[0][0];
    }
};