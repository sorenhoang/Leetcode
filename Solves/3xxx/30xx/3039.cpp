class TrieNode {
public:
    int children[26];
    int minLen;
    int minIdx;

    TrieNode() {
        for (int i = 0; i < 26; i++) {
            children[i] = -1;
        }

        minLen = -1;
        minIdx = -1;
    }

    void update(int len, int idx) {
        if (minLen == -1) {
            minLen = len;
            minIdx = idx;
            return;
        }

        if (minLen < len) return;

        if (minLen == len)
            minIdx = min(minIdx, idx);
        else {
            minLen = len;
            minIdx = idx;
        }
    }
};

class Trie {
private:
    vector<TrieNode> nodes;

public:
    Trie() {
        nodes.push_back(TrieNode());
    }

    void insert(string& word, int len, int index) {
        int current = 0;
        nodes[current].update(len, index);

        for (int i = word.size() - 1; i >= 0; i--) {
            int idx = word[i] - 'a';

            if (nodes[current].children[idx] == -1) {
                nodes[current].children[idx] = nodes.size();
                nodes.push_back(TrieNode());
            }

            current = nodes[current].children[idx];
            nodes[current].update(len, index);
        }
    }

    int query(string& word) {
        int current = 0;

        for (int i = word.size() - 1; i >= 0; i--) {
            int idx = word[i] - 'a';

            if (nodes[current].children[idx] == -1) {
                break;
            }

            current = nodes[current].children[idx];
        }

        return nodes[current].minIdx;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<int> ans;
        Trie trie;

        for (int i = 0; i < wordsContainer.size(); ++i) {
            trie.insert(wordsContainer[i], wordsContainer[i].size(), i);
        }

        for (string& s : wordsQuery) {
            ans.push_back(trie.query(s));
        }

        return ans;
    }
};