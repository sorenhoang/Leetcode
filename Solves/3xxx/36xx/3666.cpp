public
class Solution
{
private
    long Ceil(long a, long k)
    {
        return (a + k - 1) / k;
    }

public
    int MinOperations(string s, int k)
    {
        int len = s.Length, zeros = 0;

        foreach (char c in s)
        {
            if (c == '0')
                zeros++;
        }

        if (zeros == 0)
            return 0;

        else if (zeros == k)
            return 1;

        else if (k == 1)
            return zeros;

        if (k == len)
        {
            if (zeros == 0)
                return 0;

            else if (zeros == k)
                return 1;

            else
                return -1;
        }

        long res = long.MaxValue;

        if (zeros % 2 == 0)
        {
            long c1 = Ceil(zeros, k), c2 = Ceil(zeros, len - k);

            long m = Math.Max(c1, c2);

            if (m % 2 == 1)
                m++;

            res = Math.Min(res, (int)m);
        }

        if (zeros % 2 == k % 2)
        {
            long c1 = Ceil(zeros, k), c2 = Ceil(len - zeros, len - k);

            long m = Math.Max(c1, c2);

            if (m % 2 == 0)
                m++;

            res = Math.Min(res, (int)m);
        }

        return res == long.MaxValue ? -1 : (int)res;
    }
}