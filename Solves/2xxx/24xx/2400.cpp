#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfWays(int startPos, int endPos, int k)
    {
        int MOD = 1e9 + 7;
        int dist = abs(endPos - startPos);
        if (dist > k || (k - dist) % 2 != 0)
            return 0;
        int rightMoves = (k + dist) / 2;
        int leftMoves = k - rightMoves;
        long long numerator = 1;
        long long denominator = 1;
        for (int i = 1; i <= rightMoves; ++i)
        {
            numerator = (numerator * (leftMoves + i)) % MOD;
            denominator = (denominator * i) % MOD;
        }
        long long denominatorInverse = modInverse(denominator, MOD);
        return (numerator * denominatorInverse) % MOD;
    }
    long long modInverse(long long a, long long mod)
    {
        long long m0 = mod, t, q;
        long long x0 = 0, x1 = 1;

        if (mod == 1)
            return 0;

        while (a > 1)
        {
            q = a / mod;
            t = mod;

            mod = a % mod, a = t;
            t = x0;

            x0 = x1 - q * x0;
            x1 = t;
        }

        if (x1 < 0)
            x1 += m0;

        return x1;
    }
};

int main()
{
    // Input: startPos = 1, endPos = 2, k = 3
    Solution sol;
    int result = sol.numberOfWays(1, 2, 3);
    cout << result << endl; // Expected output: 3
    return 0;
}