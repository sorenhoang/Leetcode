class Solution
{
public:
    int smallestRepunitDivByK(int k)
    {
        if ((k % 2) == 0 || (k % 5) == 0)
            return -1;

        int ans = 1;
        int cnt = 1;
        while (true)
        {
            if ((cnt % k) == 0)
                return ans;
            cnt = ((cnt * 10) + 1) % k;
            ans++;
        }
        return -1;
    }
};