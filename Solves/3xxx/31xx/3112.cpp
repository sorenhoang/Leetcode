class Solution
{
    using P = std::pair<int, int>;

public:
    vector<int> minimumTime(int n, vector<vector<int>> &edges, vector<int> &disappear)
    {
        vector<vector<P>> adjList(n);
        for (const auto &edge : edges)
        {
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }
        std::priority_queue<P, vector<P>, std::greater<P>> pq;
        vector<int> minTime(n, INT_MAX);
        minTime[0] = 0;
        pq.push({0, 0});
        while (!pq.empty())
        {
            auto [currentTime, u] = pq.top();
            pq.pop();
            if (currentTime >= disappear[u])
                continue;
            if (currentTime > minTime[u])
                continue;
            for (const auto &[v, w] : adjList[u])
            {
                int nextTime = currentTime + w;
                if (nextTime < disappear[v] && nextTime < minTime[v])
                {
                    minTime[v] = nextTime;
                    pq.push({nextTime, v});
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (minTime[i] == INT_MAX)
            {
                minTime[i] = -1;
            }
        }
        return minTime;
    }
};