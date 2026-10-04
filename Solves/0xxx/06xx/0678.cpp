class Solution {
public:
    bool canTransform(string start, string result) {
        vector<pair<int, char>> s;
        vector<pair<int, char>> r;

        for (int i = 0; i < start.size(); i++) {
            if (start[i] != 'X') {
                s.push_back({i, start[i]});
            }

            if (result[i] != 'X') {
                r.push_back({i, result[i]});
            }
        }

        if (s.size() != r.size()) {
            return false;
        }

        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i].second != r[i].second) {
                return false;
            }

            if (s[i].second == 'L' && s[i].first < r[i].first) {
                return false;
            }

            if (s[i].second == 'R' && s[i].first > r[i].first) {
                return false;
            }
        }

        return true;
    }
};