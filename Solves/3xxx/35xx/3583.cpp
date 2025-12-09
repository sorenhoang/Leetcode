#include <bits/stdc++.h>
using namespace std;
const int lim = 1e5;
class Solution
{
public:
    int specialTriplets(vector<int> &nums)
    {
        vector<int> cnt(lim + 3, 0);
        vector<int> left(lim + 3, 0);
        int res = 0;
        int mod = 1e9 + 7;

        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            if (nums[i] * 2 <= lim)
            {
                left[i] = cnt[nums[i] * 2];
            }
            cnt[nums[i]]++;
        }

        fill(cnt.begin(), cnt.end(), 0);

        for (int i = n - 1; i >= 0; --i)
        {
            if (nums[i] * 2 <= lim)
            {
                int cur = cnt[nums[i] * 2];
                // cout << cur << " " << left[i] << endl;
                res = (res + 1ll * cur * left[i] % mod) % mod;
            }
            cnt[nums[i]]++;
        }

        return res;
    }
};

int main()
{
    vector<int> v{8, 4, 2, 8, 4};
    cout << Solution().specialTriplets(v) << endl;
    return 0;
}