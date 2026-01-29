#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long minimumCost(string source, string target, vector<char> &original, vector<char> &changed, vector<int> &cost)
    {
        int n = 26;
        long long max_edge = 1e15;
        vector<vector<long long>> min_path(n, vector<long long>(n, max_edge));

        for (int i = 0; i < original.size(); ++i)
        {
            int u = original[i] - 'a';
            int v = changed[i] - 'a';
            min_path[u][v] = min(min_path[u][v], 1ll * cost[i]);
        }

        for (int k = 0; k < n; ++k)
        {
            min_path[k][k] = 0;
            for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                {
                    min_path[i][j] = min(min_path[i][j], min_path[i][k] + min_path[k][j]);
                }
            }
        }
        long long res = 0;

        for (int i = 0; i < source.size(); ++i)
        {
            int u = source[i] - 'a';
            int v = target[i] - 'a';
            if (min_path[u][v] == max_edge)
                return -1;

            res += min_path[u][v];
        }

        return res;
    }
};

int main()
{
    // Input: source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
    string source = "aaaa", target = "bbbb";
    vector<char> original = {'a', 'c'};
    vector<char> changed = {'c', 'b'};
    vector<int> cost = {1, 2};
    Solution sol;
    cout << sol.minimumCost(source, target, original, changed, cost) << endl;
    return 0;
}