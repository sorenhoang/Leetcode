#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        int n = stones.size();
        vector<vector<int>> canCrossFrom(n, vector<int>());

        canCrossFrom[0].push_back(0);
        for (int i = 1; i < n; ++i)
        {
            for (int j = i - 1; j >= 0; --j)
            {
                int gap = stones[i] - stones[j];
                int id = lower_bound(canCrossFrom[j].begin(), canCrossFrom[j].end(), gap - 1) - canCrossFrom[j].begin();
                if (id == canCrossFrom[j].size())
                {
                    continue;
                }
                if (abs(canCrossFrom[j][id] - gap) > 1)
                {
                    continue;
                }
                canCrossFrom[i].push_back(gap);
            }
            // cout << "From stone " << stones[i] << " can cross with steps: ";
            // for (auto &step : canCrossFrom[i])
            //     cout << step << " ";
            // cout << endl;
        }

        return canCrossFrom[n - 1].size() > 0;
    }
};

int main()
{
    Solution s;
    // vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};
    vector<int> stones = {0, 2};
    cout << s.canCross(stones) << endl;
}