class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        multiset<long long> lo, hi;
        long long sl = 0, sr = 0, INF = 1e18;
        vector<long long> cost(n - x + 1);

        auto add = [&](long long v) {
            if (lo.empty() || v <= *lo.rbegin()) lo.insert(v), sl += v;
            else hi.insert(v), sr += v;
        };

        auto del = [&](long long v) {
            if (lo.count(v)) lo.erase(lo.find(v)), sl -= v;
            else hi.erase(hi.find(v)), sr -= v;
        };

        auto balance = [&]() {
            while (lo.size() > hi.size() + 1) {
                auto it = prev(lo.end()); long long v = *it;
                lo.erase(it); sl -= v; hi.insert(v); sr += v;
            }
            while (lo.size() < hi.size()) {
                auto it = hi.begin(); long long v = *it;
                hi.erase(it); sr -= v; lo.insert(v); sl += v;
            }
        };

        for (int i = 0; i < n; ++i) {
            add(nums[i]);
            if (i >= x) del(nums[i - x]);
            balance();

            if (i >= x - 1) {
                long long m = *lo.rbegin();
                cost[i - x + 1] = m * lo.size() - sl + sr - m * hi.size();
            }
        }

        vector<vector<long long>> dp(k + 1, vector<long long>(n + 1, INF));
        fill(dp[0].begin(), dp[0].end(), 0);

        for (int j = 1; j <= k; ++j)
            for (int i = x; i <= n; ++i)
                dp[j][i] = min(dp[j][i - 1],
                    dp[j - 1][i - x] + cost[i - x]);

        return dp[k][n];
    }
};
