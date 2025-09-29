class Solution
{
public:
    int minimizeArrayValue(vector<int> &nums)
    {
        int maxValue = 0;
        for (auto &num : nums)
        {
            maxValue = max(maxValue, num);
        }

        if (maxValue == 0)
            return 0;

        int l = 0, r = maxValue;

        while (r - l > 1)
        {
            int mid = l + (r - l) / 2;
            if (checkMinimizeArrayValue(nums, mid))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }

        return r;
    }

    bool checkMinimizeArrayValue(vector<int> &nums, int value)
    {
        int n = nums.size();
        long long prev = 0;
        for (int i = n - 1; i > 0; --i)
        {
            long long cur = nums[i] + prev;
            prev = max(0ll, cur - value);
        }

        return nums[0] + prev <= value;
    }
};