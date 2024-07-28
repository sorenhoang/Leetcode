class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        int step = (numRows - 1) * 2;
        string ans = "";
        for (int i = 1; i <= numRows; ++i) {
            int cur = i - 1;
            while (cur < s.size()) {
                ans += s[cur];
                if (i != 1 && i != numRows) {
                    int id = cur + step - (i - 1) * 2;
                    if (id < s.size())
                        ans += s[id];
                }
                cur += step;
            }
        }
        return ans;

        return ans;
    }
};