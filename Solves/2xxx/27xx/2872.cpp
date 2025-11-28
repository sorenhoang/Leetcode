class Solution
{
public:
    int maxKDivisibleComponents(int n, vector<vector<int>> &edges, vector<int> &values, int k)
    {
        vector<vector<int>> adj(n);
        for (auto &e : edges)
        {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        long long ans = 0;

        function<long long(int, int)> dfs = [&](int u, int parent) -> long long
        {
            long long sum = values[u] % k;

            for (int v : adj[u])
            {
                if (v == parent)
                    continue;
                long long childRem = dfs(v, u);
                sum = (sum + childRem) % k;
            }
            if (sum % k == 0)
            {
                ans++;
                return 0;
            }
            return sum;
        };

        dfs(0, -1);

        return (int)ans;
    }
};