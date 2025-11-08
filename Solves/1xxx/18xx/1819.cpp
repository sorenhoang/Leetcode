class Solution
{
public:
    int countDifferentSubsequenceGCDs(vector<int> &nums)
    {
        int ans = 0, mx = *max_element(nums.begin(), nums.end());
        vector<bool> present(mx + 1, false);
        for (int &num : nums)
        {
            present[num] = true;
        }

        // Checking that if I can form gcd to be 'trying'
        for (int trying = 1; trying <= mx; trying++)
        {
            // Is the gcd of the multiples of 'trying' which are present in nums, 'trying'?

            // gcd(x,0) becomes x, so smartly taking intial Value to be 0.
            // Later on, it may decrease and fall to 'trying'
            int gcdSoFar = 0;
            for (int multiple = trying; multiple <= mx; multiple += trying)
            {
                if (present[multiple])
                {
                    gcdSoFar = gcd(gcdSoFar, multiple);
                    if (gcdSoFar == trying)
                    {
                        // We can form 'trying' by taking gcd of some numbers. Yay!
                        ans++;
                        break; // Early terminate
                    }
                }
            }
        }

        return ans;
    }
};