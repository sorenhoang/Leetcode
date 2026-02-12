class Solution
{
public:
    int maxConsecutive(int bottom, int top, vector<int> &special)
    {
        // time complexity: O(n.logn)
        // space complexity: O(1)

        int i;
        int n = special.size();

        // sorting the 'special' array
        sort(special.begin(), special.end());

        // storing maximum of non-special floor's '1st special floor' and 'last special floor'
        int ans = max((special[0] - bottom), (top - special[n - 1]));
        for (i = 0; i < n - 1; i++)
        {
            // counting the 'number of floors' between two consecutive floors
            int count = special[i + 1] - special[i] - 1;
            // storing the maximum consecutive floors in 'ans'
            ans = max(ans, count);
        }
        return ans;
    }
};