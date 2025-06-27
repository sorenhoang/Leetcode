class Solution
{
public:
    bool check(string &s, string &t, int k)
    {
        int j = 0, c = 0;
        int n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == t[j])
            {
                j++;
                if (j == t.size())
                {
                    c++;
                    j = 0;
                }
                if (c == k)
                    return true;
            }
        }
        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k)
    {
        int n = s.length();
        queue<string> q;
        q.push("");
        string ans = "";
        while (!q.empty())
        {
            string cur = q.front();
            q.pop();

            for (int i = 0; i < 26; i++)
            {
                string tem = cur + char('a' + i);
                if (check(s, tem, k))
                {
                    ans = tem;
                    q.push(tem);
                }
            }
        }
        return ans;
    }
};