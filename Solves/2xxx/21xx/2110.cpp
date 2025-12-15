#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long getDescentPeriods(vector<int> &prices)
    {
        long long res = 0;

        int cur = 0;
        for (int i = 0; i < prices.size(); ++i)
        {
            if (i == 0 || prices[i] != prices[i - 1] - 1)
            {
                cur = 1;
            }
            else
            {
                cur++;
            }
            res += cur;
        }

        return res;
    }
};

int main()
{
    vector<int> prices{3, 2, 1, 4};
    cout << Solution().getDescentPeriods(prices) << endl;
    return 0;
}
