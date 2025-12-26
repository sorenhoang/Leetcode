#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int numberOfSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> oldNumIndexs{0};

        for (int i = 1; i <= n; ++i)
        {
            if (nums[i - 1] % 2)
            {
                oldNumIndexs.push_back(i);
            }
        }

        oldNumIndexs.push_back(n + 1);
        int res = 0;
        for (int i = 1; i < oldNumIndexs.size(); ++i)
        {
            if (i + k >= oldNumIndexs.size())
                break;
            res += (oldNumIndexs[i] - oldNumIndexs[i - 1]) * (oldNumIndexs[i + k] - oldNumIndexs[i + k - 1]);
        }
        return res;
    }
};

int main()
{
    vector<int> nums{2, 2, 2, 1, 2, 2, 1, 2, 2, 2};
    int k = 2;
    cout << Solution().numberOfSubarrays(nums, k) << endl;
    return 0;
}