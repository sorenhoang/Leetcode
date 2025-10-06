class Solution {
public:
    bool check(int k, vector<vector<int>>& v, int n) {
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(n));
        if (v[0][0] <= k) {
            q.push({0, 0});
            vis[0][0] = 1;
        }
        vector<pair<int, int>> mov = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        while (!q.empty()) {
            auto it = q.front();
            int x = it.first;
            int y = it.second;
            q.pop();
            if (x == n - 1 && y == n - 1)
                return true;
            for (auto val : mov) {
                int nx = val.first + x;
                int ny = val.second + y;
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && v[nx][ny] <= k && !vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& v) {
        int n = v.size();
        int low = 0;
        int high = n * n;
        int ans = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(mid, v, n)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};