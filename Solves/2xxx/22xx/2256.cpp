#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumAverageDifference(vector<int> &nums)
    {
        vector<long long> pre(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++)
            pre[i] = pre[i - 1] + nums[i - 1];
        int ans = 0, minAvgDiff = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            int leftAvg = pre[i + 1] / (i + 1);
            int rightAvg = (i == nums.size() - 1) ? 0 : (pre[nums.size()] - pre[i + 1]) / (nums.size() - i - 1);
            int avgDiff = abs(leftAvg - rightAvg);
            if (avgDiff < minAvgDiff)
            {
                minAvgDiff = avgDiff;
                ans = i;
            }
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {2, 5, 3, 9, 5, 3};
    cout << sol.minimumAverageDifference(nums) << endl;
    return 0;
}