#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long calculateScore(vector<string> &ins, vector<int> &values)
    {
        long long scr = 0;
        int n = ins.size();
        int i = 0;
        unordered_set<int> vis;

        while (i >= 0 && i < n)
        {
            if (vis.find(i) != vis.end())
            {
                break;
            }
            vis.insert(i);

            if (ins[i] == "add")
            {
                scr += values[i];
                i++;
            }
            else
            {
                int x = i + values[i];
                if (x < 0 || x >= n || vis.find(x) != vis.end())
                {
                    break;
                }
                i = x;
            }
        }

        return scr;
    }
};

int main()
{
    Solution sol;
    vector<string> instructions = {"jump", "add", "add", "jump", "add", "jump"};
    vector<int> values = {2, 1, 3, 1, -2, -3};
    cout << sol.calculateScore(instructions, values) << endl;
    return 0;
}