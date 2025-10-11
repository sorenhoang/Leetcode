#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string largestNumber(vector<int> &cost, int target)
    {
        bool visited[target + 1][target + 1];
        memset(visited, false, sizeof(visited));

        visited[0][0] = true;
        for (int i = 1; i <= target; ++i)
        {
            for (int num = 1; num <= i; ++num)
            {
                for (int x = 0; x < 9; ++x)
                {
                    if (i - cost[x] >= 0 && visited[i - cost[x]][num - 1])
                    {
                        visited[i][num] = true;
                        break;
                    }
                }
            }
        }

        int num = 0;
        for (int i = 1; i <= target; ++i)
        {
            if (visited[target][i])
                num = i;
        }
        if (num == 0)
            return "0";

        string str = "";
        while (num--)
        {
            for (int x = 8; x >= 0; --x)
            {
                if (target - cost[x] >= 0 && visited[target - cost[x]][num])
                {
                    str += to_string(x + 1);
                    target -= cost[x];
                    break;
                }
            }
        }
        return str;
    }
};

int main()
{
    Solution sol;
    vector<int> cost = {1, 1, 1, 1, 1, 1, 1, 3, 2};
    int target = 10;
    cout << sol.largestNumber(cost, target) << endl;
    return 0;
}