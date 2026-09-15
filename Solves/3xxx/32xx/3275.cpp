class Solution {
public:
    vector<int> resultsArray(vector<vector<int>>& queries, int k) {
        priority_queue<int> heap;
        vector<int> res;
        for (auto query : queries) {
            int distance = abs(query[0]) + abs(query[1]);
            heap.push(distance);
            if (k) {
                k--;
                if (k == 0)
                    res.push_back(heap.top());
                else
                    res.push_back(-1);
            }

            else {
                heap.pop();
                res.push_back(heap.top());
            }
        }

        return res;
    }
};