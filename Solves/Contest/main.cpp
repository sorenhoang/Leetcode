#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestBalanced(string s)
    {
        int res = 0;
        int n = s.size();
        vector<int> freq(26, 0);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < 26; ++j)
                freq[j] = 0;
            int cnt = 0;
            int max_val = 0;
            for (int j = i; j < n; ++j)
            {
                int c = s[j] - 'a';
                if (freq[c] == 0)
                    cnt++;
                freq[c]++;
                max_val = max(max_val, freq[c]);
                if (max_val * cnt == j - i + 1)
                    res = max(res, j - i + 1);
            }
        }
        return res;
    }
};

int main()
{
    Solution sol;
    string s = "f";
    cout << sol.longestBalanced(s) << endl;
    return 0;
}