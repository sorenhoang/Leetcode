#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int n = nums.size();
        int l = 0, h = n - 1;
        while (l <= h)
        {
            int mid = (l + h) / 2;
            if (nums[mid] == target)
                return true;
            if (nums[l] == nums[mid] && nums[mid] == nums[h])
            {
                l++;
                h--;
                continue;
            }
            if (nums[l] <= nums[mid])
            {
                if (nums[l] <= target && nums[mid] >= target)
                {
                    h = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            else
            {
                if (nums[mid] <= target && nums[h] >= target)
                {
                    l = mid + 1;
                }
                else
                {
                    h = mid - 1;
                }
            }
        }
        return false;
    }
};

int main()
{
    vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;
    Solution obj;
    cout << obj.search(nums, target);
    return 0;
}