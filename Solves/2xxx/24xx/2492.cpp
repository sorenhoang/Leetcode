class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1);

        for (const auto& road : roads) {
            int a = road[0];
            int b = road[1];
            int distance = road[2];

            graph[a].push_back({b, distance});
            graph[b].push_back({a, distance});
        }

        vector<bool> visited(n + 1, false);

        queue<int> q;
        q.push(1);
        visited[1] = true;

        int answer = INT_MAX;

        while (!q.empty()) {
            int city = q.front();
            q.pop();

            for (const auto& edge : graph[city]) {
                int nextCity = edge.first;
                int distance = edge.second;

                answer = min(answer, distance);

                if (!visited[nextCity]) {
                    visited[nextCity] = true;
                    q.push(nextCity);
                }
            }
        }

        return answer;
    }
};