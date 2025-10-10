#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string kthLargestNumber(vector<string> &nums, int k)
    {
        int n = nums.size();
        vector<vector<string>> buckets(101);
        for (const string &num : nums)
        {
            buckets[num.size()].emplace_back(num);
        }

        k = n - k + 1;
        for (int i = 1; i <= 100; ++i)
        {
            if (k > buckets[i].size())
            {
                k -= buckets[i].size();
            }
            else
            {
                sort(buckets[i].begin(), buckets[i].end());
                return buckets[i][k - 1];
            }
        }
    }
};

int main()
{
    Solution sol;
    vector<string> nums = {"3", "6", "7", "10"};
    int k = 4;
    cout << sol.kthLargestNumber(nums, k) << endl; // Output: "3"
    return 0;
}