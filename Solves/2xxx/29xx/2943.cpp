class Solution
{
public:
    int maximizeSquareHoleArea(int n, int m, vector<int> &hBars, vector<int> &vBars)
    {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());

        int c = 1;
        int maxi = 1, maxi2 = 1;
        for (int i = 1; i < hBars.size(); i++)
        {
            if (hBars[i] == hBars[i - 1] + 1)
                c++;
            else
                c = 1;
            maxi = max(maxi, c);
        }
        c = 1;
        for (int i = 1; i < vBars.size(); i++)
        {
            if (vBars[i] == vBars[i - 1] + 1)
                c++;
            else
                c = 1;
            maxi2 = max(maxi2, c);
        }
        int side = min(maxi, maxi2) + 1;
        return side * side;
    }
};