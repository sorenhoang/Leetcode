class Solution
{
public:
    int dp[53][53][53][53];
    const int M = 1e9 + 7;
    long long f(vector<int> &nums, int k, int i, int l, int prev, int sprev, int last)
    {
        if (l == k)
        {
            return abs(nums[prev] - nums[sprev]);
        }
        if (i >= nums.size())
            return 0;
        if (dp[last + 1][prev + 1][sprev + 1][l] != -1)
            return dp[last + 1][prev + 1][sprev + 1][l];
        int ans = 0;
        int x = prev;
        int y = sprev;
        if (last != -1 and (prev == -1 or sprev == -1 or abs(nums[prev] - nums[sprev]) > abs(nums[i] - nums[last])))
        {
            x = last;
            y = i;
        }
        ans = (ans + f(nums, k, i + 1, l + 1, x, y, i)) % M;
        ans = (ans + f(nums, k, i + 1, l, prev, sprev, last)) % M;
        return dp[last + 1][prev + 1][sprev + 1][l] = ans;
    }
    int sumOfPowers(vector<int> &nums, int k)
    {
        memset(dp, -1, sizeof(dp));
        sort(nums.begin(), nums.end());
        return f(nums, k, 0, 0, -1, -1, -1);
    }
};