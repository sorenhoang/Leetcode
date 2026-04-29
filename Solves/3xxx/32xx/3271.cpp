class Solution
{
public:
    string stringHash(string s, int k)
    {
        string res;
        int cur = k;
        int sum = 0;
        for (char c : s)
        {
            cur--;
            sum = (sum + (c - 'a')) % 26;
            if (cur == 0)
            {
                res = res + char(sum + 'a');
                cur = k;
                sum = 0;
            }
        }

        return res;
    }
};