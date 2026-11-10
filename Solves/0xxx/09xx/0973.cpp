class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<int, int>> distance;
        for(int i = 0; i < points.size(); ++i)
        {
            int dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            distance.emplace_back(dis, i);
        }

        sort(distance.begin(), distance.end());

        vector<vector<int>> res;
        
        for(int i = 0; i < k; ++i)
        {
            res.push_back(points[distance[i].second]);
        }

        return res;
    }
};
