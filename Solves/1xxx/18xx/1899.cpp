class Solution
{
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        int maxA = 0, maxB = 0, maxC = 0;
        for (auto triplet : triplets)
        {
            if (triplet[0] <= target[0] && triplet[1] <= target[1] && triplet[2] <= target[2])
            {
                maxA = max(maxA, triplet[0]);
                maxB = max(maxB, triplet[1]);
                maxC = max(maxC, triplet[2]);
            }
        }

        return maxA == target[0] && maxB == target[1] && maxC == target[2];
    }
};