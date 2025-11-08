#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numSub(string s)
    {
        int res = 0;
        int mod = 1e9 + 7;
        int cnt = 0;
        for (char c : s)
        {
            if (c == '0')
            {
                res = (res + 1ll * cnt * (cnt + 1) / 2 % mod) % mod;
                cnt = 0;
            }
            else
            {
                cnt++;
            }
        }
        res = (res + 1ll * cnt * (cnt + 1) / 2 % mod) % mod;
        return res;
    }
};

int main()
{
    // Input: s = "0110111"
    string s = "0110111";
    cout << Solution().numSub(s) << endl;
    return 0;
}