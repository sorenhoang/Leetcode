#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumANDSum(vector<int> &nums, int numSlots)
    {
        int ans = 0;
        int lim = (1 << (numSlots * 2)) - 1;
        vector<int> dp(lim + 1, 0);
        for (auto num : nums)
        {
            for (int mask = lim; mask >= 0; --mask)
            {
                for (int j = 0; j < numSlots * 2; ++j)
                {
                    if (getbit(mask, j) == 0)
                    {
                        int slot = j / 2 + 1;
                        int nmask = mask | (1 << j);
                        dp[nmask] = max(dp[nmask], dp[mask] + (num & slot));
                    }
                }
            }
        }
        for (int i = 0; i <= lim; ++i)
        {
            ans = max(ans, dp[i]);
        }
        return ans;
    }

    int getbit(int n, int i)
    {
        return (n >> i) & 1;
    }
};

int main()
{
    // Input: nums = [1,3,10,4,7,1], numSlots = 9
    vector<int> nums = {1, 3, 10, 4, 7, 1};
    int numSlots = 9;
    Solution sol;
    int result = sol.maximumANDSum(nums, numSlots);
    cout << "Maximum AND Sum: " << result << endl;
    return 0;
}