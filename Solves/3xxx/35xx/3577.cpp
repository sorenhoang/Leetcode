#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    const int MOD = 1e9 + 7;

public:
    int countPermutations(vector<int> &complexity)
    {
        int first = complexity[0];
        sort(complexity.begin(), complexity.end());
        if (complexity[0] == complexity[1] || complexity[0] != first)
            return 0;

        return factorial(complexity.size() - 1);
    }

    long long factorial(int n)
    {
        return (n <= 1) ? 1ll : (1ll * n * factorial(n - 1)) % MOD;
    }
};

int main()
{
    Solution sol;
    vector<int> complexity = {1, 2, 3};
    cout << sol.countPermutations(complexity) << endl;
    return 0;
}