class Solution
{
private:
    const static int maxn = 5e4 + 2;
    int pre[maxn], l[500];

public:
    int lengthOfLongestSubstring(string s)
    {
        int ans = 0;
        for (int i = 1; i <= s.size(); ++i)
        {
            char c = s[i - 1];
            pre[i] = max(pre[i - 1], l[c]);
            l[c] = i;

            ans = max(ans, i - pre[i]);
        }
        return ans;
    }
};