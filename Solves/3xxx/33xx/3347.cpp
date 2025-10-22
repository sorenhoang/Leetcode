#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        map<int, int> freq;
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int u = upper_bound(nums.begin(), nums.end(), nums[i] + k * 2) - nums.begin();
            ans = max(ans, min(numOperations, u - i));
            freq[nums[i]]++;
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            int left = lower_bound(nums.begin(), nums.end(), nums[i] - k) - nums.begin();
            int right = upper_bound(nums.begin(), nums.end(), nums[i] + k) - nums.begin();
            cout << left << " " << right << " " << freq[nums[i]] << endl;
            ans = max(ans, min(numOperations + freq[nums[i]], right - left));
        }
        return ans;
    }
};

int main()
{
    // Input: nums = [1,4,5], k = 1, numOperations = 2
    vector<int> nums = {1, 4, 5};
    int k = 1;
    int numOperations = 2;
    Solution sol;
    cout << sol.maxFrequency(nums, k, numOperations) << endl;
    return 0;
}