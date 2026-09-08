class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) 
    {
        int ans = 0;
        vector<vector<int>>temp;
        for(int i=0;i<nums.size();i++)
        {
            vector<int>t;
            for(int j=0;j<nums[i].size();j++)
            {
                t.push_back(nums[i][j]);
            }
            sort(t.begin(),t.end());
            temp.push_back(t);
        } 
        for(int i=0;i<temp[0].size();i++)
        { 
            int maxi = INT_MIN;
            for(int j=0;j<temp.size();j++)
            {
                maxi=max(maxi,temp[j][i]);
            } 
            ans+=maxi;
        } 
        return ans;
    }
//please upvote...
};