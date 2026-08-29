class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> ans(n);

        vector<pair<int, int>> newNums(0);
        for(int i = 0; i < n; ++i)
        {
            newNums.emplace_back(nums[i], i);
        }

        sort(newNums.begin(), newNums.end());
        vector<int> tmp;
        for(int i = 0; i < n; )
        {
            int prev = newNums[i].first;
            int j = i;
            while(j < n)
            {
                if(newNums[j].first-prev > limit)
                {
                    break;
                }
                prev = newNums[j].first;
                tmp.push_back(newNums[j].second);
                j++;
            }

            sort(tmp.begin(),tmp.end());
            for(int id : tmp)
            {
                ans[id] = newNums[i].first;
                i++;
            }
            tmp.clear();
        }

        return ans;
    }
};