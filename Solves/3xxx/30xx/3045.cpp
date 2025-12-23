#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    struct TrieNode
    {
        unordered_map<int, TrieNode *> child;
        int numOfEnds;
        TrieNode()
        {
            numOfEnds = 0;
        }
    };

public:
    int getIndex(char a, char b)
    {
        return (a - 'a') * 26 + (b - 'a');
    }
    int insert(TrieNode *root, const string &word)
    {
        int res = 0;
        TrieNode *cur = root;
        for (int i = 0; i < word.size(); ++i)
        {
            int idx = getIndex(word[i], word[word.size() - i - 1]);
            if (!cur->child.count(idx))
            {
                cur->child[idx] = new TrieNode();
            }
            cur = cur->child[idx];
            res += cur->numOfEnds;
        }
        cur->numOfEnds++;
        return res;
    }

    long long countPrefixSuffixPairs(vector<string> &words)
    {
        long long res = 0;
        TrieNode *root = new TrieNode();
        for (string word : words)
        {
            res += insert(root, word);
        }

        return res;
    }
};

int main()
{
    vector<string> words{"a", "aba", "ababa", "aa"};
    cout << Solution().countPrefixSuffixPairs(words);

    return 0;
}