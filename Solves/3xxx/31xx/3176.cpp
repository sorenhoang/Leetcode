#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumLength(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> dp(n + 2, vector<int>(k + 2));
        int ans = 1;
        for (int i = 1; i <= n; ++i)
        {
            dp[i][0] = 1;
            for (int j = 1; j < i; ++j)
            {
                for (int x = 0; x <= k; ++x)
                {
                    if (nums[i - 1] == nums[j - 1])
                        dp[i][x] = max(dp[i][x], dp[j][x] + 1);
                    else if (x)
                        dp[i][x] = max(dp[i][x], dp[j][x - 1] + 1);
                    ans = max(ans, dp[i][x]);
                }
            }
        }

        return ans;
    }
};

int main()
{
    vector<int> nums{1, 2, 1, 1, 3};
    cout << Solution().maximumLength(nums, 2) << endl;
}