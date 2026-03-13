#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string getHappyString(int n, int k)
    {
        vector<string> cur;
        n--;
        cur.push_back("a");
        cur.push_back("b");
        cur.push_back("c");
        while (true)
        {
            if (n == 0)
                break;
            vector<string> newCur;
            for (string str : cur)
            {
                for (char c = 'a'; c <= 'c'; ++c)
                {
                    if (str[str.size() - 1] == c)
                        continue;
                    string newStr = str + c;
                    newCur.push_back(newStr);
                }
            }
            n--;
            cur = newCur;
        }
        sort(cur.begin(), cur.end());
        if (k > cur.size())
            return "";
        return cur[k - 1];
    }
};