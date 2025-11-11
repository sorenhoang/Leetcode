class Solution
{
public:
    int sz;
    vector<int> nums;
    Solution(int n, vector<int> &blacklist)
    {
        n = min(100000, n);
        set<int> st(begin(blacklist), end(blacklist));
        for (int i = 0; i < n; i++)
            if (not(st.count(i)))
                nums.push_back(i);
        sz = nums.size();
    }

    int pick()
    {
        int idx = rand() % sz;
        return nums[idx];
    }
};