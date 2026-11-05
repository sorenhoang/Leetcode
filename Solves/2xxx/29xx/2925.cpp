class Solution {
private:
    vector<vector<int>> adj;
    int n;
    vector<long long> sum, dp;

    void dfs(vector<int>& values, int curNode, int prevNode) {
        bool isLeaf = true;
        for (auto nextNode : adj[curNode]) {
            if (nextNode == prevNode)
                continue;
            isLeaf = false;
            dfs(values, nextNode, curNode);
            sum[curNode] += sum[nextNode];
            dp[curNode] += dp[nextNode];
        }

        if (!isLeaf)
            dp[curNode] = max(values[curNode] + dp[curNode], sum[curNode]);
        sum[curNode] += values[curNode];
    }

public:
    long long maximumScoreAfterOperations(vector<vector<int>>& edges,
                                          vector<int>& values) {
        n = values.size();
        adj.resize(n, vector<int>(0));
        sum.resize(n);
        dp.resize(n);
        for (auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        dfs(values, 0, 0);

        return dp[0];
    }
};
