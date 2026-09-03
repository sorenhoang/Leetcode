class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int smallestOdd = INT_MAX;
        for (int num : nums) {
            if (num % 2 == 1)
                smallestOdd = min(smallestOdd, num);
        }
        // Already all even
        if (smallestOdd == INT_MAX)
            return true;
        // Check whether every even number can become odd
        for (int num : nums) {
            if (num % 2 == 0 && num <= smallestOdd)
                return false;
        }
        return true;
    }
};