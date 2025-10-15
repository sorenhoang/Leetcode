#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> minDifference(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        vector<int> result;
        vector<vector<int>> prefix(101, vector<int>(n + 1, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 1; j <= 100; j++)
            {
                prefix[j][i + 1] = prefix[j][i];
            }
            prefix[nums[i]][i + 1]++;
        }

        for (auto &q : queries)
        {
            int left = q[0], right = q[1];
            int minDiff = INT_MAX;
            int prev = -1;
            for (int i = 1; i <= 100; i++)
            {
                if (prefix[i][right + 1] - prefix[i][left] > 0)
                {
                    if (prev != -1)
                    {
                        minDiff = min(minDiff, i - prev);
                    }
                    prev = i;
                }
            }
            if (minDiff == INT_MAX)
            {
                result.push_back(-1);
            }
            else
            {
                result.push_back(minDiff);
            }
        }

        return result;
    }
};

int main()
{
    // Input: nums = [1,3,4,8], queries = [[0,1],[1,2],[2,3],[0,3]]
    vector<int> nums = {1, 3, 4, 8};
    vector<vector<int>> queries = {{0, 1}, {1, 2}, {2, 3}, {0, 3}};
    Solution *solution = new Solution();
    vector<int> result = solution->minDifference(nums, queries);
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    return 0;
}
