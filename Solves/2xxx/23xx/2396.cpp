class Solution {
public:
    bool isStrictlyPalindromic(int n) {
        for (int i = 2; i <= n - 2; i++) {
            int temp = n;
            string digits = "";
            while (temp > 0) {
                int rem = temp % i;
                digits = to_string(rem) + digits;
                temp /= i;
            }
            string rev = digits;
            reverse(rev.begin(), rev.end());
            if (digits != rev)
                return false;
        }
        return true;
    }
};
