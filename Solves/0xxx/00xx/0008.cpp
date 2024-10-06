class Solution {
private:
    int checkValid(long long cur) {
        if (cur > INT_MAX)
            return 1;
        if (cur < INT_MIN)
            return -1;
        return 0;
    }

public:
    long long myAtoi(string s) {
        int sign = 1;
        long long ans = 0;
        bool started = false;
        for (auto c : s) {
            if (c == '-' || c == '+') {
                if (!started) {
                    sign = c == '-' ? -1 : 1;
                    started = true;
                } else {
                    break;
                }
                continue;
            }

            if (c == ' ') {
                if (!started) {
                    continue;
                } else
                    break;
            }

            if (c >= '0' && c <= '9') {
                started = true;
                ans = ans * 10 + (c - '0');
                if (checkValid(ans * sign) != 0) {
                    return sign == -1 ? INT_MIN : INT_MAX;
                }
            }

            if (c < '0' || c > '9') {
                break;
            }
        }
        return ans * sign;
    }
};