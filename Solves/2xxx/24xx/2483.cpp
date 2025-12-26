#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int bestClosingTime(string customers)
    {
        int n = customers.size();
        int minPens = 0;
        for (char c : customers)
        {
            minPens += c == 'N';
        }

        int id = n;

        int cur = minPens;
        for (int i = n - 1; i >= 0; --i)
        {
            if (customers[i] == 'Y')
            {
                cur++;
            }
            else
                cur--;

            if (cur <= minPens)
            {
                minPens = cur;
                id = i;
            }
        }

        return id;
    }
};

int main()
{
    string str = "YYNY";

    cout << Solution().bestClosingTime(str) << endl;
    return 0;
}