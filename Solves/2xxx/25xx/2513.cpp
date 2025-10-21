#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2)
    {
        long long lcm = 1ll * divisor1 * divisor2 / __gcd(divisor1, divisor2);
        long long left = 0, right = 2e9;
        while (right - left > 1)
        {
            int mid = 1ll * (left + right) / 2;
            int commonCount = mid / lcm;
            int count1 = mid / divisor1 - commonCount;
            int count2 = mid / divisor2 - commonCount;
            int cur = mid - (count1 + count2 + commonCount);
            cur -= max(0, uniqueCnt1 - count2) + max(0, uniqueCnt2 - count1);
            if (cur >= 0)
                right = mid;
            else
                left = mid;
        }
        return right;
    }
};

int main()
{
    // Input: divisor1 = 2, divisor2 = 7, uniqueCnt1 = 1, uniqueCnt2 = 3
    Solution sol;
    int divisor1 = 2, divisor2 = 4, uniqueCnt1 = 8, uniqueCnt2 = 2;
    int result = sol.minimizeSet(divisor1, divisor2, uniqueCnt1, uniqueCnt2);
    cout << result << endl;
    return 0;
}