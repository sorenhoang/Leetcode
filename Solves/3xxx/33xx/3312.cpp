#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> gcdValues(vector<int> &nums, vector<long long> &queries)
    {
        int maxNum = *max_element(nums.begin(), nums.end());
        vector<int> divisorCount(maxNum + 1, 0);
        vector<long long> pref(maxNum + 1, 0);

        vector<pair<long long, int>> queriesOrder(queries.size());
        for (int i = 0; i < queries.size(); ++i)
            queriesOrder[i] = {queries[i], i};

        sort(queriesOrder.begin(), queriesOrder.end());

        vector<int> res(queries.size());

        for (int num : nums)
        {
            for (int i = 1; i <= sqrt(num); ++i)
            {
                if (num % i == 0)
                {
                    divisorCount[i]++;
                    if (i != num / i)
                        divisorCount[num / i]++;
                }
            }
        }

        for (int down = maxNum; down >= 1; --down)
        {
            int cnt = divisorCount[down];
            pref[down] = 1ll * cnt * (cnt - 1) / 2;
            for (int multiple = 2 * down; multiple <= maxNum; multiple += down)
                pref[down] -= pref[multiple];
        }

        for (int up = 1; up <= maxNum; ++up)
        {
            pref[up] += pref[up - 1];
        }

        int up = 1;

        for (auto &q : queriesOrder)
        {
            long long k = q.first;
            int idx = q.second;
            while (up <= maxNum && pref[up] <= k)
                up++;
            while (up <= maxNum && pref[up] - pref[up - 1] == 0) // handle duplicates
                up++;
            res[idx] = up;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 4, 2, 1};
    vector<long long> queries = {5, 3, 1, 0};
    vector<int> result = sol.gcdValues(nums, queries);
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}