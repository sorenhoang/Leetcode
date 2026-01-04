#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    struct Fenwick
    {
        vector<int> val;
        int lim;
        Fenwick() {}
        Fenwick(int n)
        {
            lim = n;
            val = vector<int>(lim + 5);
        }

        void update_tree(int id, int cur)
        {
            for (; id <= lim; id += (id & -id))
                val[id] = max(val[id], cur);
        }

        int query(int id)
        {
            int res = 0;
            if (id == 0)
                return 0;
            for (; id > 0; id -= (id & -id))
            {
                res = max(res, val[id]);
            }
            return res;
        }
    };

public:
    int minOperations(vector<int> &target, vector<int> &arr)
    {
        int n = target.size();
        int m = arr.size();
        int res = n;
        Fenwick fTree(m);
        map<int, vector<int>> indexes;

        for (int i = m; i >= 1; --i)
        {
            int c = arr[i - 1];
            indexes[c].push_back(i);
        }

        for (int i = 1; i <= n; ++i)
        {
            int c = target[i - 1];
            for (auto id : indexes[c])
            {
                int cur = fTree.query(id - 1) + 1;
                res = min(res, n - cur);
                fTree.update_tree(id, cur);
            }
        }

        return res;
    }
};

int main()
{
    // Example usage:
    Solution sol;
    vector<int> target = {6, 4, 8, 1, 3, 2};
    vector<int> arr = {4, 7, 6, 2, 3, 8, 6, 1};
    int result = sol.minOperations(target, arr);
    cout << "Minimum operations: " << result << endl;
    return 0;
}