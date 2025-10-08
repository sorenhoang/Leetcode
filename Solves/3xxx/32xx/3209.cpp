#include <bits/stdc++.h>
using namespace std;

struct Solution
{
    void initSparseTable(const vector<int> &nums, vector<vector<int>> &sparse)
    {
        int n = (int)nums.size();
        int maxLog = (n > 0) ? (32 - __builtin_clz(n)) : 1;

        sparse.assign(n, vector<int>(maxLog));
        for (int i = 0; i < n; ++i)
            sparse[i][0] = nums[i];

        for (int j = 1; j < maxLog; ++j)
        {
            int len = 1 << j;
            for (int i = 0; i + len <= n; ++i)
            {
                sparse[i][j] = sparse[i][j - 1] & sparse[i + (1 << (j - 1))][j - 1];
            }
        }
    }

    int querySparseTable(const vector<vector<int>> &sparse, int l, int r)
    {
        int len = r - l + 1;
        int k = log2(len);
        return sparse[l][k] & sparse[r - (1 << k) + 1][k];
    }

    long long countSubarrays(vector<int> &nums, int k)
    {
        int n = (int)nums.size();
        vector<vector<int>> sparse;
        initSparseTable(nums, sparse);

        long long res = 0;

        for (int i = 0; i < n; ++i)
        {
            res += (nums[i] == k);
            int low = i, high = n;
            while (high - low > 1)
            {
                int mid = (high + low) / 2;
                if (querySparseTable(sparse, i, mid) >= k)
                {
                    low = mid;
                }
                else
                {
                    high = mid;
                }
            }
            res += low;

            low = i, high = n;
            while (high - low > 1)
            {
                int mid = (high + low) / 2;
                if (querySparseTable(sparse, i, mid) > k)
                {
                    low = mid;
                }
                else
                {
                    high = mid;
                }
            }
            res -= low;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 3};
    int k = 2;
    cout << sol.countSubarrays(nums, k) << "\n";
    return 0;
}