class Solution {
public:
    int minMoves(vector<int>& nums) {
        int low = *(std::ranges::min_element(nums)); 
        int moves = 0;

        for(auto num : nums)
        {
            moves += num - low;
        }
        
        return moves;
    }
};
