#include <vector>
#include <bits/stdc++.h>
using namespace std;

// LeetCode Problem 2779: Maximum Beauty of an Array After Applying Operation

const int MAXN = 2e5 + 5;
class Solution
{
public:
    int maximumBeauty(vector<int> &nums, int k)
    {
        int ans = 0;
        int freq[MAXN] = {0};
        int cnt[MAXN] = {0};
        for (int num : nums)
        {
            cnt[max(num - k, 0)]++;
            cnt[num]--;
            cnt[num + 1]++;
            cnt[num + k + 1]--;
            freq[num]++;
        }

        for (int i = 0; i < MAXN; ++i)
        {
            if (i)
                cnt[i] += cnt[i - 1];
            ans = max(ans, freq[i] + cnt[i]);
        }
        // TODO: Implement the solution
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {4, 6, 1, 2};
    int k = 2;
    int result = solution.maximumBeauty(nums, k);
    cout << result << endl; // Expected output: 3
    // Output the result
    return 0;
}