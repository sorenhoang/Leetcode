class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> res(n, -1);

        unordered_map<int, int> hash;
        vector<int> dryDays;

        for(int i=0; i<n; i++) {
            if(rains[i] == 0) {
                dryDays.push_back(i);
            }
            else {
                int lake = rains[i];
                if(hash[lake]) {
                    int j=0;
                    while(j < dryDays.size() && dryDays[j] < hash[lake] - 1) {
                        j++;
                    }
                    if(j >= dryDays.size()) return {};
                    else {
                        res[dryDays[j]] = lake;
                        dryDays.erase(dryDays.begin()+j);
                        hash[lake] = i+1;
                    }
                } else {
                    hash[lake] = i+1;
                }
            }
        }
        for(int i=0; i<n; i++) {
            if(rains[i] == 0 && res[i] == -1) res[i] = 1;
        }
        return res;

    }
};