#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int n, m;
    int prefixSum[302][302];

public:
    int maxSideLength(vector<vector<int>> &mat, int threshold)
    {
        n = mat.size();
        m = mat[0].size();
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= m; ++j)
            {
                prefixSum[i][j] = prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1] + mat[i - 1][j - 1];
            }
        }

        int left = 0, right = min(n, m) + 1;
        while (right - left > 1)
        {
            int mid = (left + right) / 2;
            if (check(mid, threshold))
                left = mid;
            else
                right = mid;
        }
        return left;
    }

    bool check(int len, int threshold)
    {
        for (int i = len; i <= n; ++i)
        {
            for (int j = len; j <= m; ++j)
            {
                int sum = prefixSum[i][j] - prefixSum[i - len][j] - prefixSum[i][j - len] + prefixSum[i - len][j - len];
                if (sum <= threshold)
                    return true;
            }
        }
        return false;
    }
};

int main()
{
    // Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
    vector<vector<int>> mat = {{1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}, {1, 1, 3, 2, 4, 3, 2}};
    int threshold = 4;
    Solution sol;
    cout << sol.maxSideLength(mat, threshold) << endl;
    return 0;
}
