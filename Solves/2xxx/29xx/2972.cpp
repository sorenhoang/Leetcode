#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long incremovableSubarrayCount(vector<int> &nums)
    {
        int n = nums.size();

        int rightMost = 1;
        int leftMost = n;
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                rightMost = i + 1;
                continue;
            }
            break;
        }
        for (int i = n - 1; i >= 1; --i)
        {
            if (nums[i - 1] < nums[i])
            {
                leftMost = i;
                continue;
            }
            break;
        }

        if (rightMost == n)
        {
            return (long long)n * (n + 1) / 2;
        }

        long long ans = n - leftMost + 2;
        int id = leftMost;
        for (int i = 1; i <= rightMost; ++i)
        {
            while (nums[id - 1] <= nums[i - 1] && id <= n)
            {
                id++;
            }
            ans += n - id + 2;
        }
        return ans;
    }
};

int main()
{
    //[6,5,7,8]
    Solution sol;
    vector<int> nums = {6, 5, 7, 8};
    cout << sol.incremovableSubarrayCount(nums) << endl;
    return 0;
}