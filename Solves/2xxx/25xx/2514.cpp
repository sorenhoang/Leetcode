#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countAnagrams(string s)
    {
        long long MOD = 1e9 + 7;
        vector<long long> fact(101, 1);
        for (int i = 2; i <= 100; i++)
        {
            fact[i] = fact[i - 1] * i % MOD;
        }

        long long ans = 1;
        stringstream ss(s);
        string word;

        while (ss >> word)
        {
            vector<int> freq(26, 0);
            for (char c : word)
                freq[c - 'a']++;
            long long count = fact[word.size()];
            for (int f : freq)
            {
                if (f > 1)
                    count = count * pow(fact[f], MOD - 2, MOD) % MOD;
            }
            ans = ans * count % MOD;
        }

        return ans;
    }
};