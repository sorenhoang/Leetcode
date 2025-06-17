#include <bits/stdc++.h>
using namespace std;

// Uncomment the following lines if you need fast IO
// ios::sync_with_stdio(false);
// cin.tie(nullptr);

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int result = -1;
        int minValue = nums[0];
        for(int i = 1;i< nums.size();++i)
        {
            if(nums[i] > minValue)
            {
                result = max(result, nums[i] - minValue);
            }
            minValue = min(minValue, nums[i]);
        }
        return result;
    }
};

int main() {
    // Test cases
    Solution sol;
    vector<int> nums = {7, 1, 5, 4};
    cout << sol.maximumDifference(nums) << endl;
    return 0;
}
#endif