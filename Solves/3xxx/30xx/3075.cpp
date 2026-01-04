#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long maximumHappinessSum(vector<int> &happiness, int k)
    {
        long long res = 0;
        sort(happiness.begin(), happiness.end(), [](int a, int b)
             { return a > b; });
        int cur = 0;
        for (int happy : happiness)
        {
            res += max(0, happy - cur);
            cur++;
            if (cur == k)
                break;
        }
        return res;
    }
};

int main()
{
    vector<int> happiness{12, 1, 42};
    int k = 3;
    cout << Solution().maximumHappinessSum(happiness, k) << endl;
    return 0;
}