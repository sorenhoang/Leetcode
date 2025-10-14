#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int makeConnected(int n, vector<vector<int>> &connections)
    {
        if (connections.size() < n - 1)
            return -1;

        vector<int> parent(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
        int com = 0;
        for (auto &edge : connections)
        {
            int u = edge[0];
            int v = edge[1];
            int pu = find_parent(u, parent);
            int pv = find_parent(v, parent);
            if (pu != pv)
            {
                parent[pu] = pv;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            com += (parent[i] == i);
        }
        return com - 1;
    }

    int find_parent(int node, vector<int> &parent)
    {
        if (parent[node] == node)
            return node;
        return parent[node] = find_parent(parent[node], parent);
    }
};

int main()
{
    // Input: n = 4, connections = [[0,1],[0,2],[1,2]]
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
    Solution sol;
    int ans = sol.makeConnected(n, connections);
    cout << ans << endl;
    return 0;
}
