#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int res = 0;
        int n = prices.size();
        if (n < 2)
            return 0;
        vector<int> max_profit_right(n, 0);
        int max_right = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            max_right = max(max_right, prices[i]);
            max_profit_right[i] = max_right - prices[i];
        }

        int minPrice = prices[0];
        int maxProfitLeft = 0;
        for (int i = 0; i < n; i++)
        {
            if (i)
            {
                minPrice = min(minPrice, prices[i]);
                maxProfitLeft = max(maxProfitLeft, prices[i] - minPrice);
            }

            if (i + 1 < n)
                res = max(res, maxProfitLeft + max_profit_right[i + 1]);
        }

        return max(res, maxProfitLeft);
    }
};

int main()
{
    Solution sol;
    vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
    cout << sol.maxProfit(prices) << endl; // Output: 6
    return 0;
}