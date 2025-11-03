class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int res = 0;
        int total = 0;
        int maxTime = 0;
        char lastC = '*';
        for (int i = 0; i < colors.size(); ++i)
        {
            if (colors[i] != lastC)
            {
                res += total - maxTime;
                maxTime = 0;
                total = 0;
            }
            maxTime = max(maxTime, neededTime[i]);
            total += neededTime[i];
            lastC = colors[i];
        }

        res += total - maxTime;
        return res;
    }
};