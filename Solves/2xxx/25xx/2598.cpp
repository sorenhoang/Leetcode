#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findSmallestInteger(vector<int> &nums, int value)
    {
        vector<int> freq(value, 0);
        for (auto num : nums)
        {
            freq[(num % value + value) % value]++;
        }

        int left = 0, right = nums.size();
        while (right - left > 1)
        {
            int mid = (left + right) / 2;
            if (CheckCanBeMEXOrExisted(mid, freq, value))
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }

        return left;
    }

    bool CheckCanBeMEXOrExisted(int mex, vector<int> &freq, int value)
    {
        int temp = mex / value;
        int rem = mex % value;
        for (int i = 0; i < value; i++)
        {
            if (i < rem && freq[i] < temp + 1)
                return false;
            if (i >= rem && freq[i] < temp)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, -10, 7, 13, 6, 8};
    int value = 7;
    cout << sol.findSmallestInteger(nums, value) << endl;
    return 0;
}