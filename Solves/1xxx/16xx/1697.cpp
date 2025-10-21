#include <bits/stdc++.h>
using namespace std;

class Solution
{

public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>> &edgeList, vector<vector<int>> &queries)
    {
        vector<bool> res(queries.size());
        vector<int> p(n);
        sort(edgeList.begin(), edgeList.end(), [](vector<int> &a, vector<int> &b)
             { return a[2] < b[2]; });
        for (int i = 0; i < n; ++i)
            p[i] = i;
        int m = queries.size();

        for (int i = 0; i < m; ++i)
        {
            queries[i].push_back(i);
        }

        sort(queries.begin(), queries.end(), [](vector<int> &a, vector<int> &b)
             { return a[2] < b[2]; });
        int last = 0;
        for (auto query : queries)
        {
            cout << query[0] << " " << query[1] << " " << query[2] << endl;
            while (last < edgeList.size())
            {
                auto edge = edgeList[last];
                if (edge[2] >= query[2])
                    break;

                int u = edge[0];
                int v = edge[1];
                u = findParrent(p, u);
                v = findParrent(p, v);
                if (u != v)
                    p[u] = v;
                last++;
            }

            int st = findParrent(p, query[0]);
            int fn = findParrent(p, query[1]);
            res[query[3]] = st == fn;
        }

        for (auto edge : edgeList)
        {
            cout << edge[0] << " " << edge[1] << " " << edge[2] << endl;
        }
        return res;
    }
    int findParrent(vector<int> &p, int node)
    {
        if (p[node] == node)
            return node;
        return p[node] = findParrent(p, p[node]);
    }
};

int main()
{
    Solution sol;
    // Input: n = 3, edgeList = [[0,1,2],[1,2,4],[2,0,8],[1,0,16]], queries = [[0,1,2],[0,2,5]]
    int n = 3;
    vector<vector<int>> edgeList{{0, 1, 2}, {1, 2, 4}, {2, 0, 8}, {1, 0, 16}};
    vector<vector<int>> queries{{0, 1, 2}, {0, 2, 5}};
    vector<bool> res = sol.distanceLimitedPathsExist(n, edgeList, queries);
    for (bool item : res)
    {
        cout << item << " ";
    }
    return 0;
}
