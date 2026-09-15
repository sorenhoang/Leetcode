class Solution {
public:
    int paint(int i, int j, int c, vector<vector<int>>& g, bool flip = false) {
        if (!flip && (min(i, j) < 0 || i >= g.size() || j >= g[0].size() ||
                      g[i][j] == 0 || g[i][j] == c))
            return 0;
        g[i][j] = g[i][j] == 0 ? 0 : c;
        return 1 + paint(i + 1, j, c, g) + paint(i - 1, j, c, g) +
               paint(i, j + 1, c, g) + paint(i, j - 1, c, g);
    }
    int largestIsland(vector<vector<int>>& g, int res = 0) {
        for (int i = 0; i < g.size(); ++i)
            for (int j = 0; j < g[i].size(); ++j)
                if (g[i][j] == 0) {
                    res = max(res, paint(i, j, 2, g, true));
                    paint(i, j, 1, g, true);
                }
        return res == 0 ? g.size() * g[0].size() : res;
    }
};