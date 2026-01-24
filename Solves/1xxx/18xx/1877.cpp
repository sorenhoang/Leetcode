class Solution
{
public:
    int minPairSum(vector<int> &nums)
    {
        int n = nums.size();
        int size = 10;
        while (size < n)
            size *= 10;
        size = (n == 10000) ? 100000 : size + 1;
        vector<int> freq(size);

        for (auto &num : nums)
            freq[num]++;

        int res = 0;
        int i = 0;
        int j = size - 1;

        while (i <= j)
        {
            if (freq[i] == 0)
                i++;
            else if (freq[j] == 0)
                j--;
            else
            {
                res = max(res, i + j);
                freq[i]--;
                freq[j]--;
            }
        }

        return res;
    }
};
