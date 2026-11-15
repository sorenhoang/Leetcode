class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        int radius = 0;
        
        for (int house : houses) {
            auto it = lower_bound(heaters.begin(), heaters.end(), house);
            int dist1 = (it == heaters.end()) ? INT_MAX : *it - house;
            int dist2 = (it == heaters.begin()) ? INT_MAX : house - *(--it);
            radius = max(radius, min(dist1, dist2));
        }
        
        return radius;
    }
};
