#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        string t = "$";
        for (char c : s)
        {
            t += "#";
            t += c;
        }
        t += "#^";
        cout << t << endl;
        vector<int> p = manacher_init(t);
        int ans = 0;
        for (int i = 1; i < p.size() - 1; ++i)
        {
            ans += (p[i] + (i % 2 ? 0 : 2)) / 2;
        }

        return ans;
    }

    vector<int> manacher_init(string s)
    {
        int R = 0, C = 0;
        int n = s.size();
        vector<int> p(n, 0);

        for (int i = 1; i < n; ++i)
        {
            if (i < R)
            {
                int mirror = 2 * C - i;
                p[i] = min(p[mirror], R - i);
            }

            while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && s[i + p[i] + 1] == s[i - p[i] - 1])
                p[i]++;

            if (i + p[i] > R)
            {
                C = i;
                R = i + p[i];
            }
        }
        return p;
    }
};

int main()
{
    // Input: s = "aac"
    string s = "aac";
    cout << Solution().countSubstrings(s) << endl;
    return 0;
}