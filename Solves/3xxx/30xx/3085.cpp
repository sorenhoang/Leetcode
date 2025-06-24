#include <bits/stdc++.h>
using namespace std;

// LeetCode Problem 3085

const int MAXN = 1e5 + 5;

class Solution
{
private:
    int freq[26] = {0};  // Frequency of each character in the word
    int cnt[MAXN] = {0}; // Cumulative frequency array

public:
    int minimumDeletions(string word, int k)
    {
        for (char c : word)
        {
            freq[c - 'a']++;
        }

        for (int i = 0; i <= 25; i++)
        {
            if (freq[i] > 0)
            {
                cnt[freq[i]]++;
            }
        }

        for (int i = 1; i < MAXN; i++)
        {
            cnt[i] = cnt[i - 1] + cnt[i] * i;
        }
        int n = word.size();
        int ans = n; // Initialize answer to maximum possible deletions
        int cur = 0;
        int numOfOver = 0;
        for (int i = MAXN - 1; i > k; --i)
        {
            cur += numOfOver;

            ans = min(ans, cur + cnt[i - k - 1]);

            numOfOver += (cnt[i] - cnt[i - 1]) / i; // Count how many characters have frequency i
        }

        return ans;
    }
};
int main()
{
    Solution sol;
    // Example usage:
    cout << sol.minimumDeletions("aabcaba", 0) << endl;
    // cout << sol.minimumDeletions("dabdcbdcdcd", 2) << endl;
    // cout << sol.minimumDeletions("aaabaaa", 2) << endl;
    return 0;
}