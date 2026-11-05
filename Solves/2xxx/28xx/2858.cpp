class Solution {
    vector<vector<int>> adj;
    vector<int> sumBelow, sumAbove;

public:
    vector<int> minEdgeReversals(int n, vector<vector<int>>& edges) {
        sumBelow.resize(n + 1);
        sumAbove.resize(n + 1);
        adj.resize(n + 1);

        for (auto& edge : edges) {
            int u = edge[0] + 1;
            int v = edge[1] + 1;

            // u -> v
            adj[u].push_back(v);

            // v -> u is against original direction
            adj[v].push_back(-u);
        }

        // DFS 1: bottom-up
        dfsBelow(1, 0);

        // DFS 2: top-down
        dfsAbove(1, 0);

        vector<int> ans(n);

        for (int u = 1; u <= n; ++u) {
            ans[u - 1] = sumBelow[u] + sumAbove[u];
        }

        return ans;
    }

private:

    void dfsBelow(int u, int parent) {

        for (int x : adj[u]) {
            int v = abs(x);

            if (v == parent)
                continue;

            dfsBelow(v, u);

            sumBelow[u] += sumBelow[v] + (x < 0);
        }
    }

    void dfsAbove(int u, int parent) {

        for (int x : adj[u]) {
            int v = abs(x);

            if (v == parent)
                continue;

            int edgeCost = (x < 0);

            int restOfSubtree = sumBelow[u] - sumBelow[v] - edgeCost;

            int parentEdgeCost = (x > 0);

            sumAbove[v] = sumAbove[u] + restOfSubtree + parentEdgeCost;

            dfsAbove(v, u);
        }
    }
};
