class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        std::unordered_set<int> s(nums.begin(), nums.end());
        vector<int> newNums;
        for (auto& num : s) {
            int cur = __builtin_popcount(num);
            newNums.push_back(cur);
        }

        sort(newNums.begin(), newNums.end());

        long long ans = 0;
        for (auto num : newNums) {
            auto it = lower_bound(newNums.begin(), newNums.end(), k - num);
            ans += (newNums.end() - it);
        }
        return ans;
    }
};
