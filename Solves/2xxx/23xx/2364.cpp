#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        int n = nums.size();
        long long res = 1ll * n * (n - 1) / 2;

        map<int, int> myMap;

        for (int i = 1; i <= n; ++i)
        {
            int diff = nums[i - 1] - i;
            res -= myMap[diff];
            myMap[diff]++;
        }

        return res;
    }
};

int main()
{
    vector<int> nums{4, 1, 3, 3};
    cout << Solution().countBadPairs(nums) << endl;

    return 0;
}