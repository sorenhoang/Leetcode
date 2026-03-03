#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int lim = 31;
        int n = nums.size();
        vector<vector<int>> indxBit(lim + 1, vector<int>(0));
        vector<int> countBit(lim + 1);
        vector<int> res(n);
        for (int i = n - 1; i >= 0; --i) {
            int num = nums[i];
            for (int bit = 0; bit <= lim; ++bit) {
                if ((num >> bit) & 1) {
                    indxBit[bit].push_back(i);
                    countBit[bit]++;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            int cur = i;
            for (int bit = 0; bit <= lim; ++bit) {
                if (countBit[bit] > 0) {
                    cur = max(cur, indxBit[bit].back());
                }
            }
            res[i] = cur - i + 1;
            int num = nums[i];
            for (int bit = 0; bit <= lim; ++bit) {
                if ((num >> bit) & 1) {
                    indxBit[bit].pop_back();
                    countBit[bit]--;
                }
            }
        }

        return res;
    }
};