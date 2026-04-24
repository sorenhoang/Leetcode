class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res (n, 0);
        vector<pair<int,int>> newNums;

        for(int i = 0; i < n; ++i)
        {
            newNums.emplace_back(nums[i],i);
        }

        sort(newNums.begin(), newNums.end());

        int cnt = 0;
        long long curSum = 0;
        for(int i = 0; i < n; ++i)
        {
            if(i == 0 || newNums[i].first != newNums[i-1].first) 
            {
                cnt = 0;
                curSum = 0;
            }

            cnt ++;
            curSum += newNums[i].second;

            res[newNums[i].second] += 1ll * cnt * newNums[i].second - curSum;
        }

        for(int i = n-1; i >= 0; --i)
        {
            if(i == n-1 || newNums[i].first != newNums[i+1].first) 
            {
                cnt = 0;
                curSum = 0;
            }

            cnt ++;
            curSum += newNums[i].second;

            res[newNums[i].second] += curSum - 1ll * cnt * newNums[i].second;
        }

        return res;
    }
};