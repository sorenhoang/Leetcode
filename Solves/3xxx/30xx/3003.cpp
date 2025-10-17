#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxPartitionsAfterOperations(string s, int k)
    {
        int res = 0;
        int n = s.size();
        s = " " + s;
        vector<vector<int>> pre(n + 1, vector<int>(26, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 26; ++j)
            {
                pre[i][j] = pre[i - 1][j];
            }
            pre[i][s[i] - 'a']++;
        }

        vector<int> suff(n + 2, 0);
        vector<int> startIndex(n + 1, 0);
        vector<int> nextIndex(n + 1, 0);

        for (int i = n; i >= 1; --i)
        {
            int r = n + 1, l = i;
            while (r - l > 1)
            {
                int mid = (l + r) / 2;
                if (countDiff(i, mid, pre) <= k)
                {
                    l = mid;
                }
                else
                {
                    r = mid;
                }
            }
            nextIndex[i] = l + 1;
            suff[i] = suff[l + 1] + 1;
        }
        int st = 1;
        int cur = 0;
        res = suff[1];
        for (int i = 1; i <= n; ++i)
        {
            if (i >= nextIndex[st])
            {
                st = i;
                cur++;
            }

            startIndex[i] = st;
            int charAtThis = s[i] - 'a';

            for (int c = 0; c < 26; ++c)
            {
                int newSt = st;
                int r = n + 1, l = i;
                pre[i][charAtThis]--;
                pre[i][c]++;
                if (countDiff(st, i, pre) > k)
                {
                    newSt = i;
                }

                pre[i][charAtThis]++;
                pre[i][c]--;

                while (r - l > 1)
                {
                    int mid = (l + r) / 2;

                    pre[mid][c]++;
                    pre[mid][charAtThis]--;

                    if (countDiff(newSt, mid, pre) <= k)
                    {
                        l = mid;
                    }
                    else
                    {
                        r = mid;
                    }

                    pre[mid][c]--;
                    pre[mid][charAtThis]++;
                }
                res = max(res, cur + suff[l + 1] + 1 + (newSt != st));
            }
        }
        return res;
    }

    int countDiff(int l, int r, vector<vector<int>> &pre)
    {
        int cnt = 0;
        for (int i = 0; i < 26; ++i)
        {
            if ((pre[r][i] - pre[l - 1][i]) > 0)
            {
                cnt++;
            }
        }
        return cnt;
    }
};

int main()
{
    // Input: s = "accca", k = 2
    Solution sol;
    cout << sol.maxPartitionsAfterOperations("accca", 2) << endl;
    return 0;
}