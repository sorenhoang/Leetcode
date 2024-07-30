class Solution {
public:
    long long reverse(long long x) {
        long long ans = 0;

        int sign = (x > 0) ? 1 : -1;

        x = abs(x);

        while (x != 0 && x % 10 == 0) {
            x /= 10;
        }

        while (x) {
            ans = ans * 10 + (x % 10);
            x /= 10;
        }

        ans = ans * sign;
        if (ans > INT_MAX || ans < INT_MIN) {
            return 0;
        }
        return ans;
    }
};