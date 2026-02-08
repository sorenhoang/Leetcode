class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> arr(n, 1);
        int p = 1;
        for (int i = 0; i < n; i++)
        {
            arr[i] = p;
            p *= nums[i];
        }
        int s = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            arr[i] *= s;
            s *= nums[i];
        }

        return arr;
    }
};