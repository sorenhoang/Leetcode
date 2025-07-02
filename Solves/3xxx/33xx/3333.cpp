#include <bits/stdc++.h>
using namespace std;

// LeetCode Problem #3333

class Solution
{
private:
    const int mod = 1e9 + 7;
    vector<int> nums;
    int dp[2][2005] = {0};

public:
    // Define your function here
    int possibleStringCount(string word, int k)
    {
        int i = 0;
        while (i < word.size())
        {
            int j = i;
            while (word[j] == word[i] && j < word.size())
            {
                j++;
            }
            nums.push_back(j - i);
            i = j;
        }

        for (auto &num : nums)
        {
            num--;
            k--;
        }

        k = max(k, 0);

        int id = 0;
        dp[0][0] = 1;
        for (auto num : nums)
        {
            if (num == 0)
            {
                continue;
            }

            id = 1 ^ id;
            for (int j = 0; j <= k; ++j)
            {
                int prev = dp[1 ^ id][j];
                int max_j = min(k, j + num);
                dp[id][j] = (dp[id][j] + prev) % mod;

                dp[id][max_j + 1] = (dp[id][max_j + 1] - prev + mod) % mod;

                if (j + num > k)
                {
                    int rem = j + num - k;
                    dp[id][k] = (dp[id][k] + 1ll * prev * rem) % mod;
                }
            }

            for (int j = 0; j <= k; ++j)
            {
                dp[id ^ 1][j] = 0;
                if (j > 0)
                    dp[id][j] = (dp[id][j] + dp[id][j - 1]) % mod;
            }
        }

        return dp[id][k];
    }
};

int main()
{
    freopen("input.txt", "r", stdin);
    string s;
    int k;
    cin >> s >> k;
    Solution sol;
    // Example usage:
    cout << sol.possibleStringCount(s, k) << endl;
    return 0;
}