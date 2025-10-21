#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxFrequency(vector<int> &nums, int k, int numOperations)
    {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int lim = 1e5;
        vector<int> freq(lim + 1);
        for (auto &x : nums)
            freq[x]++;

        for (int target = 1; target <= lim; ++target)
            freq[target] += freq[target - 1];

        for (int target = 1; target <= lim; ++target)
        {
            int low = max(1, target - k);
            int hight = min(lim, target + k);
            int total = freq[hight] - freq[low - 1];
            ans = max(ans, min(total, numOperations + freq[target] - freq[target - 1]));
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