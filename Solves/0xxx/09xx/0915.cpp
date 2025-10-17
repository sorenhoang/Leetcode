#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int partitionDisjoint(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> leftMax(n), rightMin(n);
        leftMax[0] = nums[0];
        for (int i = 1; i < n; ++i)
        {
            leftMax[i] = max(leftMax[i - 1], nums[i]);
        }
        rightMin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; --i)
        {
            rightMin[i] = min(rightMin[i + 1], nums[i]);
        }
        for (int i = 0; i < n - 1; ++i)
        {
            if (leftMax[i] <= rightMin[i + 1])
                return i + 1;
        }
        return 0;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {5, 0, 3, 8, 6};
    int result = sol.partitionDisjoint(nums);
    cout << result << endl;
    return 0;
}