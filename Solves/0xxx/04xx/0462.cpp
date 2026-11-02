class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        long long sum = std::accumulate(nums.begin(), nums.end(), 0);

        long long ans = INT_MAX;
        long long curSum = 0;

        for (int id = 0; id < n; ++id) {
            curSum += nums[id];
            sum -= nums[id];
            long long cur = 1ll * nums[id] * (id + 1) - curSum;
            cur += sum - 1ll * (n - id - 1) * nums[id];

            ans = min(ans, cur);
        }

        return (int)ans;
    }
};
