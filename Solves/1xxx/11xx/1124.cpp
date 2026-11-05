class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        unordered_map<int, int> m;
        int cur = 0;
        int ans = 0;

        for(int i = 1; i <= n; ++i)
        {
            cur += (hours[i-1] > 8 ? 1 : -1);
            if(cur > 0)
            {
                ans = max(ans, i);
            }
            else{
                int x = m[cur -1];
                if(x!=0)
                {
                    ans = max(ans, i - x);
                }
            }

            if(!m[cur]) m[cur] = i;
            
        }

        return ans;
    }
};
