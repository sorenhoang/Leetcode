#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int nxt = 0;
        int ans = n - 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            while (nxt < n && 1ll * nums[i] * k >= 1ll * nums[nxt])
                nxt++;
            cout << i
                    ans = min(ans, n - nxt + i);
        }
        return ans;
    }
};