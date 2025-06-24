#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int count = 0;
        for (const auto &p1 : points)
        {
            unordered_map<int, int> distMap;
            for (const auto &p2 : points)
            {
                if (p1 != p2)
                {
                    int dist = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
                    distMap[dist]++;
                }
            }
            for (const auto &entry : distMap)
            {
                count += entry.second * (entry.second - 1);
            }
        }
        return count;
    }
};

int main()
{
    Solution sol;
    // Example usage:
    vector<vector<int>> points = {{0, 0}, {1, 0}, {2, 0}};
    cout << sol.numberOfBoomerangs(points) << endl; // Output: 2
    return 0;
}