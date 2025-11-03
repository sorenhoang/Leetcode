class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int cur = 0;
        int ans = 0;
        for(string s: bank)
        {
            int cnt = std::count(s.begin(), s.end(), '1');
            if(cnt)
            {
                ans += cnt*cur;
                cur = cnt;
            }
        }
        return ans;
    }
};