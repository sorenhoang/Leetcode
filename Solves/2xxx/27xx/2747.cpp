class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        vector<pair<int, int>> newArrays;
        vector<int> res(queries.size());
        for (auto log : logs) {
            newArrays.emplace_back(log[1], -log[0] - 1);
        }

        for (int i = 0; i < queries.size(); ++i) {
            newArrays.emplace_back(queries[i], i);
        }

        queue<pair<int, int>> q;
        map<int, int> lastAppear;

        sort(newArrays.begin(), newArrays.end());
        int curServers = 0;

        for (auto query : newArrays) {
            int time = query.first;
            int idx = query.second;

            if (idx < 0) {
                idx = abs(idx);
                q.emplace(time, idx);

                if (lastAppear[idx] == 0) {
                    curServers++;
                }

                lastAppear[idx] = time;
            } else {
                int prevTime = max(0, time - x);

                while (!q.empty()) {
                    auto iter = q.front();

                    if (iter.first < prevTime) {
                        if (lastAppear[iter.second] == iter.first) {
                            lastAppear[iter.second] = 0;
                            curServers--;
                        }

                        q.pop();
                        continue;
                    }
                    
                    break;
                }

                res[idx] = n - curServers;
            }
        }

        return res;
    }
};
