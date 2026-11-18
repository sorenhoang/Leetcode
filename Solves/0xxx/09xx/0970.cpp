class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> result;
        for (long a = 1; a < bound; a *= x) {
            for (long b = 1; a + b <= bound; b *= y) {
                result.insert(a + b);
                if (y == 1) break;
            }
            if (x == 1) break;
        }
        return vector<int>(result.begin(), result.end());
    }
};
