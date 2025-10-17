#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int dp[100005][2];
    vector<int> adj[100005];

public:
    long long maxOutput(int n, vector<vector<int>> &edges, vector<int> &price)
    {
        if (n == 1)
            return 0;
        long long res = 0;
        for (int i = 0; i < n; ++i)
        {
            dp[i][1] = -1e9;
        }

        for (auto &e : edges)
        {
            adj[e[0]].emplace_back(e[1]);
            adj[e[1]].emplace_back(e[0]);
        }
        dfs(0, -1, price, res);

        return res;
    }

    void dfs(int node, int parent, vector<int> &price, long long &res)
    {
        if (adj[node].size() == 1 && parent != -1)
        {
            dp[node][0] = price[node];
            dp[node][1] = 0;
            return;
        }

        for (auto nxtNode : adj[node])
        {
            if (nxtNode == parent)
                continue;
            dfs(nxtNode, node, price, res);
            res = max(res, 1ll * max(dp[nxtNode][0] + dp[node][1], dp[nxtNode][1] + dp[node][0]) + price[node]);
            res = max(res, 1ll * dp[nxtNode][0]);
            dp[node][0] = max(dp[node][0], dp[nxtNode][0]);
            dp[node][1] = max(dp[node][1], dp[nxtNode][1]);
        }
        dp[node][0] += price[node];
        dp[node][1] += price[node];
    }
};
int main()
{
    // Input: n = 6, edges = [[0,1],[1,2],[1,3],[3,4],[3,5]], price = [9,8,7,6,10,5]
    Solution sol;
    int n = 2;
    vector<vector<int>> edges = {{0, 1}};
    vector<int> price = {3, 8};
    long long res = sol.maxOutput(n, edges, price);
    cout << res << endl; // Expected output: 24
    return 0;
}