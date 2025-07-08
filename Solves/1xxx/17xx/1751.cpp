#include <bits/stdc++.h>
using namespace std;

// LeetCode Problem: 1751. Maximum Number of Events That Can Be Attended II

class Solution
{
public:
    int maxValue(vector<vector<int>> &events, int k)
    {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> dp(n + 2, vector<int>(k + 2, 0));

        for (int i = n - 1; i >= 0; --i)
        {
            for (int j = 1; j <= k; ++j)
            {
                int nxt = lower_bound(events.begin(), events.end(), vector<int>{events[i][1], INT_MAX, INT_MAX}) - events.begin();
                dp[i][j] = max(dp[i + 1][j], dp[nxt][j - 1] + events[i][2]);
            }
        }
        return dp[0][k];
    }
};

int main()
{
    Solution sol;
    // Example usage:
    vector<vector<int>> events = {{1, 2, 4}, {3, 4, 3}, {2, 3, 1}};
    int k = 2; // Maximum number of events to attend
    cout << sol.maxValue(events, k) << endl;
    return 0;
}