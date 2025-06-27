class Solution
{
public:
    void ps(vector<int> &nums, int i, vector<vector<int>> &ss, vector<int> &ans)
    {
        if (i == nums.size())
        {
            ss.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        ps(nums, i + 1, ss, ans);
        ans.pop_back();
        ps(nums, i + 1, ss, ans);
    }
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> ss;
        vector<int> ans;
        ps(nums, 0, ss, ans);
        return ss;
    }
};