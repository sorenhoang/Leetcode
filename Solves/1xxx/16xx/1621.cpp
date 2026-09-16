class Solution {

    private:
    static constexpr long long MOD = 1000000007LL;

    long long quickPow(long long a, long long e) {

        long long result = 1;

        while (e > 0) {

            if ((e & 1) != 0)
                result = (result * a) % MOD;

            a = (a * a) % MOD;
            e >>= 1;
        }

        return result;
    }

    public:
    int numberOfSets(int n, int k) {

        int m = 2 * k;

        long long numerator = 1;
        long long denominator = 1;

        for (int i = 1; i <= m; i++) {

            numerator =
                (numerator * (n + k - i)) % MOD;

            denominator =
                (denominator * i) % MOD;
        }

        return static_cast<int>(
            (numerator * quickPow(denominator, MOD - 2)) % MOD
        );
    }
};