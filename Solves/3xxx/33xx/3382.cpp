#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxRectangleArea(vector<int> &xCoord, vector<int> &yCoord)
    {
        long long res = -1;
        vector<pair<int, int>> pointX, pointY;
        int n = xCoord.size();
        for (int i = 0; i < n; i++)
        {
            pointX.push_back({xCoord[i], yCoord[i]});
            pointY.push_back({xCoord[i], yCoord[i]});
        }

        sort(pointX.begin(), pointX.end());
        sort(pointY.begin(), pointY.end(), [](pair<int, int> &a, pair<int, int> &b)
             {
            if (a.second == b.second)
                return a.first < b.first;
            return a.second < b.second; });
        for (int bot_left = 0; bot_left < n; bot_left += 200)
        {
            cout << pointX[bot_left].first << ' ' << pointX[bot_left].second << '\n';
            int bot_right = bot_left + 1;
            cout << pointX[bot_right].first << ' ' << pointX[bot_right].second << '\n';
            if (bot_right >= n || pointX[bot_left].first != pointX[bot_right].first)
                continue;

            int top_left = lower_bound(pointY.begin(), pointY.end(), pointX[bot_left]) - pointY.begin() + 1;
            cout << pointY[top_left].first << ' ' << pointY[top_left].second << '\n';
            if (top_left >= n || pointY[top_left].second != pointX[bot_left].second)
                continue;

            int top_right = lower_bound(pointX.begin(), pointX.end(), pointY[top_left]) - pointX.begin() + 1;
            cout << pointX[top_right].first << ' ' << pointX[top_right].second << '\n';
            if (top_right >= n || pointX[top_right].first != pointY[top_left].first)
                continue;

            if (top_right >= n || pointX[top_right].second != pointX[bot_right].second)
                continue;

            cout << "Area: " << (long long)(pointX[top_right].second - pointX[bot_left].second) * (pointX[top_right].first - pointX[bot_left].first) << '\n';
            res = max(res, (long long)(pointX[top_right].second - pointX[bot_left].second) * (pointX[top_right].first - pointX[bot_left].first));
        }
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    // xCoord = [1,1,3,3,1,3], yCoord = [1,3,1,3,2,2]
    vector<int> xCoord = {1, 1, 3, 3, 1, 3};
    vector<int> yCoord = {1, 3, 1, 3, 2, 2};
    Solution sol;
    cout << sol.maxRectangleArea(xCoord, yCoord) << '\n';
    return 0;
}