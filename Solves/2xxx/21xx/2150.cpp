#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findLonely(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> res;

        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (i > 0 && nums[i] - nums[i - 1] <= 1)
                continue;
            if (i < n - 1 && nums[i + 1] - nums[i] <= 1)
                continue;
            res.push_back(nums[i]);
        }

        return res;
    }
};

int main()
{
    // Input: nums = [10,6,5,8]
    vector<int> nums = {10, 6, 5, 5, 8};
    Solution sol;
    vector<int> res = sol.findLonely(nums);
    for (int x : res)
    {
        cout << x << " ";
    }
}
