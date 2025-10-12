#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLeastNumOfUniqueInts(vector<int> &arr, int k)
    {
        vector<pair<int, int>> freq;
        unordered_map<int, int> count_map;
        for (int num : arr)
            count_map[num]++;
        for (auto &entry : count_map)
            freq.push_back({entry.second, entry.first});
        sort(freq.begin(), freq.end());
        int res = freq.size();
        for (auto &p : freq)
        {
            if (k >= p.first)
            {
                k -= p.first;
                res--;
            }
            else
                break;
        }

        return res;
    }
};

int main()
{
    Solution sol;
    vector<int> arr = {5, 5, 4};
    int k = 1;
    cout << sol.findLeastNumOfUniqueInts(arr, k) << endl; // Output: 1
    return 0;
}