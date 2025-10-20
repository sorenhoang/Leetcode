#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minLength(string s, int numOps)
    {
        if (countWithSize1(s) <= numOps)
            return 1;
        int left = 1, right = s.size();
        vector<int> groups;
        char c = '-';
        int cnt = 0;
        for (char ch : s)
        {
            if (ch != c)
            {
                groups.push_back(cnt);
                c = ch;
                cnt = 1;
            }
            else
            {
                cnt++;
            }
        }
        groups.push_back(cnt);

        while (right - left > 1)
        {
            int mid = (left + right) / 2;
            if (check(groups, mid, numOps))
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }

        return right;
    }

    bool check(vector<int> &groups, int size, int numOps)
    {
        int numNeeded = 0;

        for (auto g : groups)
        {
            numNeeded += g / (size + 1);
        }

        return numNeeded <= numOps;
    }

    int countWithSize1(string s)
    {
        int cur = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            cur += (s[i] - '0' != i % 2);
        }
        return min(cur, (int)s.size() - cur);
    }
};

int main()
{
    // Input: s = "000001", numOps = 1
    Solution sol;
    cout << sol.minLength("000001", 1) << endl;
    return 0;
}
