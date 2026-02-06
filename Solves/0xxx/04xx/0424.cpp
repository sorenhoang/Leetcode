#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        int ans = 0;
        int n = s.size();
        vector<vector<int>> countChar(n + 1, vector<int>(26, 0));
        s = ' ' + s;
        for (int i = 1; i <= n; ++i)
        {
            for (int c = 0; c < 26; ++c)
            {
                countChar[i][c] = countChar[i - 1][c];
            }
            countChar[i][s[i] - 'A']++;
        }

        int r = 1;
        for (int i = 1; i <= n; ++i)
        {
            while (r <= n)
            {
                int diff = r - i + 1;
                for (int c = 0; c < 26; ++c)
                {
                    int x = r - i + 1 - (countChar[r][c] - countChar[i - 1][c]);
                    diff = min(diff, x);
                }
                if (diff <= k)
                    r++;
                else
                    break;
            }

            ans = max(ans, r - i);
        }

        return ans;
    }
};

int main()
{
    cout << Solution().characterReplacement("ABAB", 2) << endl;
}