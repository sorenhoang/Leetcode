class Solution {
public:
    int maximumLength(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = upper_bound(nums.begin(), nums.end(), 1) - nums.begin();
        if(ans%2==0) ans --;
        ans = max(ans, 1);
        int n = nums.size();

        for(int i = 0; i<n-1; ++i)
        {
            if(nums[i]!= nums[i+1] || nums[i] == 1) continue;
            int cnt = 1;
            long long cur = nums[i];
            int id = i;
            while(id <= n)
            {
                cur = cur * cur;
                id = lower_bound(nums.begin(), nums.end(), cur) - nums.begin();
                if(id >= n || nums[id] != cur)
                    break;
                
                cnt += 2;
                if(id >= n-1 || nums[id] != nums[id+1]) break;
            }
            ans = max(ans, cnt);
        }

        return ans;
    }
};