#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxIncreasingSubarrays(vector<int> &nums)
    {
        int left = 1, right = nums.size() + 1;
        while (right - left > 1)
        {
            int mid = (left + right) / 2;
            if (checkMaxSize(nums, mid))
                left = mid;
            else
                right = mid;
        }
        return left;
    }

    bool checkMaxSize(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cur = 0;
        vector<int> max_subarrays(nums.size(), 0);
        for (int i = n - 1; i >= 0; --i)
        {
            if (i + 1 >= n || nums[i] >= nums[i + 1])
                cur = 1;
            else
                cur++;
            max_subarrays[i] = cur;
            if (cur >= k && i + k < n && max_subarrays[i + k] >= k)
                return true;
        }
        return false;
    }
};

int main()
{
    Solution sol;
    vector<int> nums{2, 5, 7, 8, 9, 2, 3, 4, 3, 1};
    cout << sol.maxIncreasingSubarrays(nums);
}
