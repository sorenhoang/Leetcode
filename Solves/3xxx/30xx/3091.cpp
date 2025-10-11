class Solution
{
public:
    int minOperations(int k)
    {
        int res = k - 1;
        int cur = 1;
        for (int i = 2; i <= k; ++i)
        {
            int num = (k - 1) / i;
            res = min(res, num + i - 1);
        }

        return res;
    }
};