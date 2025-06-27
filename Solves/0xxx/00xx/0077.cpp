class Solution
{
public:
    void solve(vector<vector<int>> &ans, vector<int> v, int n, int k, int ind)
    {
        if (v.size() == k)
        {
            ans.push_back(v);
            return;
        }

        for (int i = ind; i <= n; i++)
        {
            v.push_back(i);
            solve(ans, v, n, k, i + 1);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k)
    {

        vector<vector<int>> ans;
        vector<int> v;
        int ind = 1;
        solve(ans, v, n, k, ind);
        return ans;
    }
};