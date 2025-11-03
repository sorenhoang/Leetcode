#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestPalindrome(vector<string> &words)
    {
        bool hasMiddle = false;
        int res = 0;
        unordered_map<string, int> mp;
        for (auto &word : words)
        {
            mp[word]++;
        }

        for (auto m : mp)
        {
            string rev = m.first;
            if (rev[0] == rev[1])
            {
                res += 4 * (m.second / 2);
                if (m.second % 2 == 1)
                {
                    hasMiddle = true;
                }
                continue;
            }
            reverse(rev.begin(), rev.end());
            if (mp.find(rev) != mp.end())
            {
                res += 4 * min(m.second, mp[rev]);
                mp[rev] = 0;
            }
        }

        res += hasMiddle ? 2 : 0;
        return res;
    }
};