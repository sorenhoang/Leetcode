#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(long long num, int base)
    {
        string s;
        while (num > 0)
        {
            int digit = num % base;
            s += (digit < 10) ? ('0' + digit) : ('A' + digit - 10);
            num /= base;
        }
        string rev = s;
        reverse(rev.begin(), rev.end());
        return s == rev;
    }

    long long kMirror(int k, int n)
    {
        long long ans = 0;
        int left = 1;
        while (true)
        {
            long long right = left * 10;

            for (int o = 0; o < 2; ++o)
            {
                for (long long i = left; i < right; ++i)
                {

                    long long x = o == 0 ? i / 10 : i;
                    long long temp = i;
                    while (x > 0)
                    {
                        temp = temp * 10 + x % 10;
                        x /= 10;
                    }
                    if (isPalindrome(temp, k))
                    {
                        ans += temp;
                        n--;
                        if (n == 0)
                            return ans;
                    }
                }
            }
            left = right;
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution sol;
    vector<pair<int, int>> inputs = {{2, 5}, {3, 7}, {7, 17}};
    for (auto input : inputs)
    {
        int k = input.first;
        int n = input.second;
        cout << "k = " << k << ", n = " << n << " => ";
        cout << sol.kMirror(k, n) << endl;
    }
    // Your code here

    return 0;
}