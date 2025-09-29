#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maxFreeTime(int eventTime, int k, vector<int> &startTime, vector<int> &endTime)
    {
        int ans = 0;
        startTime.push_back(eventTime);
        endTime.push_back(eventTime);
        vector<int> freeTime(startTime.size(), 0);
        int cur = 0;
        for (int i = 0; i < startTime.size(); i++)
        {
            freeTime[i] = startTime[i] - cur;
            cur = endTime[i];
        }
        cur = 0;
        for (int i = 0; i < freeTime.size(); i++)
        {
            cur += freeTime[i];
            ans = max(ans, cur);
            if (i >= k)
            {
                cur -= freeTime[i - k];
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    // Input: eventTime = 5, k = 1, startTime = [1,3], endTime = [2,5]
    // Output: 2
    int eventTime = 5, k = 1;
    vector<int> startTime = {1, 3};
    vector<int> endTime = {2, 5};
    int result = sol.maxFreeTime(eventTime, k, startTime, endTime);
    cout << "Maximum free time: " << result << endl; // Expected output: 2

    return 0;
}