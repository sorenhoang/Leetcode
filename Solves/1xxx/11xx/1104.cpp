class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> res;
        int lim = 1;
        while (lim <= label) {
            lim *= 2;
        }
        while (label) {
            lim /= 2;
            res.push_back(label);
            int rem = label - lim + 1;
            int index = (rem + 1) / 2;
            label = lim - index;
        }
        reverse(res.begin(), res.end());

        return res;
    }
};
