#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    vector<pair<int, int>> adj[50005];
    vector<int> dp;

public:
    int minCost(int n, vector<vector<int>> &edges)
    {
        dp.resize(n, 1e9);
        dp[0] = 0;
        const int maxVal = 1e9;

        for (auto edge : edges)
        {
            adj[edge[0]].emplace_back(edge[1], edge[2]);
            adj[edge[1]].emplace_back(edge[0], edge[2] * 2);
        }

        dijkstra();

        return dp[n - 1] == 1e9 ? -1 : dp[n - 1];
    }

    void dijkstra()
    {
        priority_queue<pair<int, int>> qheap;

        qheap.emplace(dp[0], 0);

        while (qheap.size())
        {
            int u = qheap.top().second;
            qheap.pop();

            for (auto edge : adj[u])
            {
                int v = edge.first;
                int w = edge.second;

                if (dp[v] > dp[u] + w)
                {
                    dp[v] = dp[u] + w;
                    qheap.emplace(-dp[v], v);
                }
            }
        }
    }
};

int main()
{
    // Input: n = 4, edges = [[0,1,3],[3,1,1],[2,3,4],[0,2,2]]
    int n = 4;
    vector<vector<int>> edges = {{0, 1, 3}, {3, 1, 1}, {2, 3, 4}, {0, 2, 2}};
    Solution sol;
    cout << sol.minCost(n, edges) << endl;
    return 0;
}