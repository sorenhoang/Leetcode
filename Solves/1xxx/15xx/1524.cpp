class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int mod = 1e9 + 7;
        vector<int> count(2, 0);
        count[0] = 1;
        int ans = 0;
        int cur = 0;
        for (auto num : arr) {
            cur = (cur + num) % 2;
            ans = (ans + count[1 - cur]) % mod;
            count[cur]++;
        }

        return ans;
    }
};
