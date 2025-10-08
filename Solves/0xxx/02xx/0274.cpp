#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = citations.size() - 1; i >= 0; --i)
        {
            if (citations[i] >= i + 1)
            {
                return i + 1;
            }
        }
        return 0;
    }
};

int main()
{
    Solution sol = Solution();
    vector<int> citations = {3, 0, 6, 1, 5};
    int result = sol.hIndex(citations);
    cout << result << endl;
    return 0;
}