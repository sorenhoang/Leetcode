#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canSortArray(vector<int> &nums)
    {
        int last = 0;
        for (int i = 0; i < nums.size();)
        {
            int nxt = i;
            int numBits = count(nums[i]);
            int minVal = nums[i];
            int maxVal = nums[i];
            while (nxt < nums.size())
            {
                if (count(nums[nxt]) != numBits)
                    break;
                minVal = min(minVal, nums[nxt]);
                maxVal = max(maxVal, nums[nxt]);

                nxt++;
            }

            if (minVal <= last)
                return false;
            last = maxVal;
            i = nxt;
        }
        return true;
    }

    int count(int n)
    {
        return __builtin_popcount(n);
    }
};

int main()
{
    // Input: nums = [8,4,2,30,15]
    vector<int> nums{8, 4, 2, 30, 15};
    cout << Solution().canSortArray(nums) << endl;
    return 0;
}