#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxTwoEvents(vector<vector<int>> &events)
    {
        int res = 0;
        sort(events.begin(), events.end());
        int n = events.size();
        vector<int> max_left(n, 0);
        for (int i = 0; i < n; ++i)
        {
            if (i)
                max_left[i] = max(max_left[i], max_left[i - 1]);

            res = max(res, max_left[i] + events[i][2]);

            vector<int> id{events[i][1] + 1, 0, 0};

            int nxt = lower_bound(events.begin(), events.end(), id) - events.begin();
            if (nxt < n)
            {
                max_left[nxt] = max(max_left[nxt], events[i][2]);
            }
        }

        return res;
    }
};

int main()
{
    vector<vector<int>> events{{1, 5, 3}, {1, 5, 1}, {6, 6, 5}};

    cout << Solution().maxTwoEvents(events);

    return 0;
}