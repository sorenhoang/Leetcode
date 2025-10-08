#include <bits/stdc++.h>

using namespace std;
class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        vector<int> ans;
        sort(potions.begin(), potions.end());
        for (auto spell : spells)
        {
            long long need = (success + spell - 1) / spell;
            auto it = lower_bound(potions.begin(), potions.end(), need);
            ans.push_back(potions.end() - it);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> spells = {5, 1, 3}, potions = {1, 2, 3, 4, 5};
    long long success = 7;
    vector<int> ans = sol.successfulPairs(spells, potions, success);
    for (auto x : ans)
        std::cout << x << " ";
    return 0;
}