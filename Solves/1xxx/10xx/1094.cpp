#include <iostream>
#include <vector>
using namespace std;

// LeetCode 1094: Car Pooling
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> stops(1001, 0);
        for (auto& trip : trips) {
            stops[trip[1]] += trip[0];
            stops[trip[2]] -= trip[0];
        }
        int curr = 0;
        for (int i = 0; i < stops.size(); ++i) {
            curr += stops[i];
            if (curr > capacity) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> trips = {{2,1,5},{3,3,7}};
    int capacity = 4;
    cout << boolalpha << sol.carPooling(trips, capacity) << endl;
    return 0;
}