class Solution {
private:
    long long convert(int x) {
        if (x == 0)
            return x;
        long long ans = 0;
        while (x) {
            ans = ans * 10 + x % 10;
            x /= 10;
        }
        return ans;
    }

public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        return convert(x) == 1ll * x;
    }
};