class Trie {

public:
    Trie* child[2];
    int minValue;
    Trie() {
        child[0] = nullptr;
        child[1] = nullptr;
        minValue = INT_MAX;
    }

    void insert(const int& num) {
        Trie* curNode = this;

        // Root also contains this number
        curNode->minValue = min(curNode->minValue, num);

        for (int idx = 30; idx >= 0; idx--) {
            int bit = (num >> idx) & 1;

            if (!curNode->child[bit]) {
                curNode->child[bit] = new Trie();
            }

            curNode = curNode->child[bit];

            // Minimum number present in this subtree
            curNode->minValue = min(curNode->minValue, num);
        }
    }

    int getMaxXor(const int& num, const int& val) {
        int xorValue = 0;
        Trie* curNode = this;

        for (int idx = 30; idx >= 0; idx--) {

            int bit = (num >> idx) & 1;

            // For maximum XOR, we prefer the opposite bit.
            int desiredBit = bit ^ 1;

            // Try opposite bit first, but only if that
            // subtree contains some number <= val.
            if (curNode->child[desiredBit] &&
                curNode->child[desiredBit]->minValue <= val) {

                xorValue |= (1 << idx);
                curNode = curNode->child[desiredBit];
            }
            else {
                // Opposite bit either doesn't exist or
                // doesn't contain any valid number.
                curNode = curNode->child[bit];
            }
        }

        return xorValue;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        Trie* trie = new Trie();
        
        for(auto num : nums)
        {
            trie -> insert(num);
        }


        for(auto query : queries)
        {
            int num = query[0];
            int lim = query[1];

            if(trie -> minValue > lim)
            {
                res.push_back(-1);
            }
            else 
            {
                res.push_back(trie -> getMaxXor(num, lim));
            }

        }

        return res;
    }
};
