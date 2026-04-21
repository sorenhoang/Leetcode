#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxIncreasingGroups(vector<int> &usageLimits)
    {
        int cur = 0, total = 0;
        for (int i = 0; i < (usageLimits.size()); ++i)
        {
            total += usageLimits[i];
            if (total >= ((cur + 1) * (cur + 2)) / 2)
                cur++;
        }
        return cur;
    }
};