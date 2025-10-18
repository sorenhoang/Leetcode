#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int smallestDistancePair(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());

        int left = -1, right = 1e6;
        while (right - left > 1)
        {
            int mid_distance = (left + right) / 2;
            if (orderOfDistance(nums, mid_distance) >= k)
            {
                right = mid_distance;
            }
            else
            {
                left = mid_distance;
            }
        }

        return right;
    }

    long long orderOfDistance(vector<int> &nums, int distance)
    {
        long long ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int left = upper_bound(nums.begin(), nums.end(), nums[i] + distance) - nums.begin();
            ans += left - i - 1;
        }

        return ans;
    }
};

int main()
{
    // Input: nums = [1,3,1], k = 1
    Solution sol;
    vector<int> nums{1, 3, 1};
    int k = 1;
    cout << "Output:" << sol.smallestDistancePair(nums, k) << endl;
    return 0;
}
