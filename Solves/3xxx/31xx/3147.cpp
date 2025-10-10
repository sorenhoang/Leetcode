#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumEnergy(vector<int> &energy, int k)
    {
        vector<int> total(k, 0);
        int n = energy.size();
        int ans = INT_MIN;
        for (int i = n - 1; i >= 0; i--)
        {
            total[i % k] += energy[i];
            ans = max(ans, total[i % k]);
        }
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> energy = {5, 2, -10, -5, 1};
    int k = 3;
    Solution sol;
    cout << sol.maximumEnergy(energy, k) << '\n';
    return 0;
}