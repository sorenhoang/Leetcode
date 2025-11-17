class Solution
{
public:
    typedef pair<int, int> P;
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        int n = tasks.size();

        vector<array<int, 3>> sortedTasks;

        for (int i = 0; i < n; i++)
        {
            int start_time = tasks[i][0];
            int processing_time = tasks[i][1];

            sortedTasks.push_back({start_time, processing_time, i});
        }

        sort(begin(sortedTasks), end(sortedTasks));

        long long currTime = 0;
        int idx = 0;

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> ans;

        while (idx < n || !pq.empty())
        {
            if (pq.empty() && currTime < sortedTasks[idx][0])
            {
                currTime = sortedTasks[idx][0];
            }

            while (idx < n && sortedTasks[idx][0] <= currTime)
            {
                pq.push({sortedTasks[idx][1], sortedTasks[idx][2]});
                idx++;
            }

            auto topTask = pq.top();
            pq.pop();

            currTime += topTask.first;
            ans.push_back(topTask.second);
        }
        return ans;
    }
};