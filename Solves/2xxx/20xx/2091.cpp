#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
            return 1;
        int maxIdx = max_element(nums.begin(), nums.end()) - nums.begin();
        int minIdx = min_element(nums.begin(), nums.end()) - nums.begin();
        if (maxIdx < minIdx)
            swap(maxIdx, minIdx);
        return min({n - maxIdx + minIdx + 1, maxIdx + 1, n - minIdx});
    }
};

int main()
{
    vector<int> nums = {2, 10, 7, 5, 4, 1, 8, 6};
    Solution obj;
    cout << obj.minimumDeletions(nums);
    return 0;
}