#include <bits/stdc++.h>
using namespace std;

// LeetCode Problem: 1498. Number of Subsequences That Satisfy the Given Sum Condition

class Solution
{
private:
    // Function to calculate power with modulo
    int pow(int base, int exp, int mod)
    {
        long long result = 1;
        long long b = base % mod;
        while (exp > 0)
        {
            if (exp % 2 == 1)
            {
                result = (result * b) % mod;
            }
            b = (b * b) % mod;
            exp /= 2;
        }
        return result;
    }

public:
    int numSubseq(vector<int> &nums, int target)
    {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        int count = 0;
        const int MOD = 1e9 + 7;

        while (left <= right)
        {
            if (nums[left] + nums[right] <= target)
            {
                count = (count + pow(2, right - left, MOD)) % MOD;
                left++;
            }
            else
            {
                right--;
            }
        }
        return count;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {3, 5, 6, 7};
    int target = 9;
    int result = solution.numSubseq(nums, target);
    cout << "Number of subsequences: " << result << endl;
    return 0;
}