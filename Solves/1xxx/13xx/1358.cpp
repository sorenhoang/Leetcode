class Solution {
public:
    int numberOfSubstrings(string s) {
        int last_a = 0, last_b = 0, last_c = 0;
        int ans = 0;
        for(int i = 1;i <= s.size(); ++i)
        {
            last_a = (s[i-1] == 'a') ? i : last_a;
            last_b = (s[i-1] == 'b') ? i : last_b;
            last_c = (s[i-1] == 'c') ? i : last_c;

            ans += min(last_a, min(last_b, last_c));
        }

        return ans;
    }
};