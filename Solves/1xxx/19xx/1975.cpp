#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxMatrixSum(vector<vector<int>> &matrix)
    {
        long long res = 0;
        bool hasZero = 0;
        int countNeg = 0;
        int minVal = 1e9;
        for (auto arr : matrix)
        {
            for (auto val : arr)
            {
                res += abs(val);
                minVal = min(minVal, abs(val));
                countNeg += (val < 0);
                if (val == 0)
                    hasZero = true;
            }
        }

        if (hasZero || countNeg % 2 == 0)
            return res;
        return res - minVal * 2;
    }
};

int main()
{
    //[[1,2,3],[-1,-2,-3],[1,2,3]]
    vector<vector<int>> matrix{{1, 2, 3}, {-1, -2, -3}, {1, 2, 3}};

    cout << Solution().maxMatrixSum(matrix) << endl;
    return 0;
}