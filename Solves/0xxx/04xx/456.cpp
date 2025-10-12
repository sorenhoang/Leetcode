#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool find132pattern(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return false;
        vector<vector<int>> st;
        sparse_table(nums, st);
        vector<int> min_left(n);
        for (int i = 0; i < n; ++i)
        {
            min_left[i] = nums[i];
            if (i > 0)
                min_left[i] = min(min_left[i], min_left[i - 1]);
            else
                continue;
            int l = -1, r = i - 1;
            while (r - l > 1)
            {
                int mid = (l + r) >> 1;
                if (min_left[mid] < nums[i])
                {
                    r = mid;
                }
                else
                    l = mid;
            }

            if (min_left[r] >= nums[i])
                continue;

            int max_mid = query(st, r, i - 1);
            if (max_mid > nums[i])
                return true;
        }
        return false;
    }

    void sparse_table(vector<int> &nums, vector<vector<int>> &st)
    {
        int n = nums.size();
        int k = log2(n) + 1;
        st.resize(n, vector<int>(k));
        for (int i = 0; i < n; i++)
            st[i][0] = nums[i];
        for (int j = 1; j < k; j++)
            for (int i = 0; i + (1 << j) <= n; i++)
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }

    int query(vector<vector<int>> &st, int l, int r)
    {
        int j = log2(r - l + 1);
        return max(st[l][j], st[r - (1 << j) + 1][j]);
    }
};

int main()
{
    Solution s;
    vector<int> v = {1, -4, 2, -1, 3, -3, -4, 0, -3, -1};
    cout << s.find132pattern(v) << endl;
    return 0;
}