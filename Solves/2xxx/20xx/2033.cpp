#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minOperations(vector<vector<int>> &grid, int x)
    {
        vector<int> all;

        for (auto &row : grid)
        {
            for (int num : row)
            {
                all.push_back(num);
            }
        }

        int mod = all[0] % x;
        for (int num : all)
        {
            if (num % x != mod)
                return -1;
        }

        sort(all.begin(), all.end());
        int median = all[all.size() / 2];
        int operations = 0;

        for (int num : all)
        {
            operations += abs(num - median) / x;
        }

        return operations;
    }
};