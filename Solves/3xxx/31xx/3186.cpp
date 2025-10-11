#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long maximumTotalDamage(vector<int> &power)
    {
        sort(power.begin(), power.end());
        long long result = 0;
        vector<pair<int, int>> newPowers;
        for (int p : power)
        {
            if (newPowers.empty() || newPowers.back().first != p)
            {
                newPowers.push_back({p, 1});
            }
            else
            {
                newPowers.back().second++;
            }
        }

        vector<long long> dp(newPowers.size(), 0);

        for (int i = 0; i < newPowers.size(); ++i)
        {
            int p = newPowers[i].first;
            int c = newPowers[i].second;

            dp[i] = 1ll * p * c;

            int up = upper_bound(newPowers.begin(), newPowers.end(), make_pair(p - 2, 0)) - newPowers.begin() - 1;
            if (up >= 0)
            {
                dp[i] += dp[up];
            }
            if (i > 0)
            {
                dp[i] = max(dp[i], dp[i - 1]);
            }

            result = max(result, (long long)dp[i]);
        }
        return result;
    }
};

int main()
{
    Solution sol;
    vector<int> power = {1, 1, 3, 4};
    cout << sol.maximumTotalDamage(power) << endl;
    return 0;
}