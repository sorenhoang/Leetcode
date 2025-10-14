#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long validSubstringCount(string word1, string word2)
    {
        long long res = 0;
        int n = word1.size();
        vector<int> freq(26, 0);
        vector<int> cnt(26, 0);
        int numDistinct = 0;
        int numValid = 0;
        for (char c : word2)
        {
            if (freq[c - 'a'] == 0)
                numDistinct++;
            freq[c - 'a']++;
        }

        int right = 0;
        for (int i = 0; i < n; ++i)
        {
            int c = word1[i] - 'a';
            while (right < n && numValid < numDistinct)
            {
                c = word1[right] - 'a';
                if (freq[c] > 0)
                {
                    cnt[c]++;
                    if (cnt[c] == freq[c])
                        numValid++;
                }
                right++;
            }

            if (numValid == numDistinct)
                res += n - right + 1;

            c = word1[i] - 'a';
            if (freq[c] > 0)
            {
                cnt[c]--;
                if (cnt[c] < freq[c])
                    numValid--;
            }
        }
        return res;
    }
};

int main()
{
    // Input: word1 = "abcabc", word2 = "abc"
    string word1 = "abcabc", word2 = "abc";
    Solution sol;
    cout << sol.validSubstringCount(word1, word2) << endl;
    return 0;
}