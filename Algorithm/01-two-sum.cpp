class Solution {
private:
    map<int, int> M;
public:
    // complexity : O(nlogn)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        for (int i = 0; i < nums.size(); ++i) {
            if (M[target - nums[i]] != 0) {
                result.push_back(M[target - nums[i]] - 1);
                result.push_back(i);
                return result;
            }
            M[nums[i]] = i + 1;
        }

        return result;
    }
};