class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        vector<vector<int>> res;
        int n = firstList.size(), m = secondList.size();
        vector<int> cnt((n + m) * 2 + 3, 0);
        vector<int> mapping;
        for (auto &v : firstList)
        {
            mapping.push_back(v[0]);
            mapping.push_back(v[1] + 1);
        }
        for (auto &v : secondList)
        {
            mapping.push_back(v[0]);
            mapping.push_back(v[1] + 1);
        }

        sort(mapping.begin(), mapping.end());
        mapping.erase(unique(mapping.begin(), mapping.end()), mapping.end());

        for (auto &v : firstList)
        {
            int s = lower_bound(mapping.begin(), mapping.end(), v[0]) - mapping.begin() + 1;
            int e = lower_bound(mapping.begin(), mapping.end(), v[1] + 1) - mapping.begin() + 1;
            cnt[s]++;
            cnt[e]--;
        }

        for (auto &v : secondList)
        {
            int s = lower_bound(mapping.begin(), mapping.end(), v[0]) - mapping.begin() + 1;
            int e = lower_bound(mapping.begin(), mapping.end(), v[1] + 1) - mapping.begin() + 1;
            cnt[s]++;
            cnt[e]--;
        }

        for (int i = 1; i <= (n + m) * 2 + 1; i++)
        {
            cnt[i] += cnt[i - 1];
            if (cnt[i] == 2)
            {
                res.push_back({mapping[i - 1], mapping[i] - 1});
            }
        }
        return res;
    }
};