#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequencyScore(vector<int> nums, long k)
    {
        sort(nums.begin(), nums.end());
        int left = 0, maxFreq = 1;
        long cost = 0;
        int med = 0;
        for (int right = 1; right < nums.size(); right++)
        {
            cost += nums[right] - nums[med];
            med = (left + right + 1) / 2;
            while (cost > k)
            {
                cost -= nums[med] - nums[left];
                left++;
                med = (left + right + 1) / 2;
            }

            maxFreq = max(maxFreq, right - left + 1);
        }

        return maxFreq;
    }
};

int main()
{
    // Input: nums = [1,2,6,4], k = 3
    //
    vector<int> nums = {1, 2, 6, 4};
    long long k = 3;
    Solution sol;
    int ans = sol.maxFrequencyScore(nums, k);
    cout << ans << endl;
    return 0;
}
