#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> res;
        for (string query : queries) {
            bool ok = false;
            for (string val : dictionary) {
                if (canMake(query, val)) {
                    ok = true;
                    break;
                }
            }
            if (ok)
                res.push_back(query);
        }

        return res;
    }

    bool canMake(string src, string target) {
        if (src.size() != target.size())
            return false;
        int cnt = 0;
        for (int i = 0; i < src.size(); ++i) {
            cnt += src[i] != target[i];
        }
        return cnt <= 2;
    }
};