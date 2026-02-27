class Solution {
public:
    int minOperations(string s, int k) {
        int zerocount = 0;
        for (auto &i : s)
            if (i == '0')
                zerocount++;

        int n = s.size();

        // handle special cases first
        if (zerocount == 0)
            return 0;

        // if k equals full length, only works when all are 0s, else impossible
        if (k == n)
            return (zerocount == n) ? 1 : -1;

        int ans = INT_MAX;

        // case when m is odd (zerocount is even)
        if (zerocount % 2 == 0) {
            // m must be large enough to fill k slots with 1s and remaining slots with 0s
            int m = max((zerocount + k - 1) / k, (zerocount + n - k - 1) / (n - k));
            // align m to odd
            ans = (m % 2 == 0) ? m : m + 1;
        }

        // case when m is even (zerocount and k have same parity)
        if (zerocount % 2 == k % 2) {
            // m must cover 0s in k slots and non-0s in remaining slots
            int m = max((zerocount + k - 1) / k, (n - zerocount + n - k - 1) / (n - k));
            // align m to even
            ans = min(ans, (m % 2 == 1) ? m : m + 1);
        }

        // if no valid ans found, return -1
        return (ans == INT_MAX) ? -1 : ans;
    }
};