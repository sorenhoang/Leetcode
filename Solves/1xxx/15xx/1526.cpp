#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minNumberOperations(vector<int> &target)
    {
        int numOfIsland = 0;
        int ans = 0;
        int n = target.size();
        vector<vector<int>> newTarget(n, vector<int>(2, 0));
        vector<int> parent(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++)
        {
            newTarget[i][0] = target[i];
            newTarget[i][1] = i;
        }

        sort(newTarget.begin(), newTarget.end(), [](vector<int> &a, vector<int> &b)
             { return a[0] > b[0]; });

        int id = 0;
        while (id < n)
        {
            int height = newTarget[id][0];
            int cur = 0;
            int nextId = id;
            while (nextId < n && newTarget[nextId][0] == height)
            {
                int index = newTarget[nextId][1];
                if (index > 0 && target[index - 1] >= height)
                {
                    unionSet(index, index - 1, parent, numOfIsland);
                }
                if (index < n - 1 && target[index + 1] >= height)
                {
                    unionSet(index, index + 1, parent, numOfIsland);
                }
                numOfIsland++;
                nextId++;
            }
            int nextHeight = (nextId < n) ? newTarget[nextId][0] : 0;

            ans += (height - nextHeight) * numOfIsland;
            id = nextId;
        }
        return ans;
    }

    void unionSet(int index1, int index2, vector<int> &parent, int &numOfIsland)
    {
        int par1 = findParent(index1, parent);
        int par2 = findParent(index2, parent);
        if (par1 != par2)
        {
            parent[par2] = par1;
            numOfIsland--;
        }
    }

    int findParent(int index, vector<int> &parent)
    {
        if (parent[index] == index)
        {
            return index;
        }
        return parent[index] = findParent(parent[index], parent);
    }
};

int main()
{
    // Input: target = [1,2,3,2,1]
    vector<int> target = {1, 2, 3, 2, 1};
    auto sol = Solution();
    cout << sol.minNumberOperations(target) << endl;
    return 0;
}