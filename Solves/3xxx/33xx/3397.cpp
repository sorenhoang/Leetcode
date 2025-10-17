#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxDistinctElements(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int distinctCount = 0;
        int minCur = -1e9;
        for (auto num : nums)
        {
            if (minCur >= num + k)
            {
                continue;
            }

            minCur = max(minCur + 1, num - k);
            distinctCount++;
        }
        return distinctCount;
    }
};

int main()
{
    // Input: nums = [4,4,4,4], k = 1
    vector<int> nums = {4, 4, 4, 4};
    int k = 1;

    Solution sol;
    int result = sol.maxDistinctElements(nums, k);
    cout << "Output: " << result << endl;

    return 0;
}