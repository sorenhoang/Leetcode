#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        if (n1 == 0 || s2.empty()) {
            return 0;
        }

        int l1 = s1.length();
        int l2 = s2.length();
        vector<int> next(n1);
        vector<int> count(n1);
        int cnt = 0;
        int p = 0;

        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < l1; ++j) {
                if (s1[j] == s2[p]) {
                    ++p;
                }
                if (p == l2) {
                    ++cnt;
                    p = 0;
                }
            }

            count[i] = cnt;
            next[i] = p;
            for (int j = 0; j < i; ++j) {
                if (next[j] == p) {
                    int previousCount = count[j];
                    int patternCount = (count[i] - count[j]) *
                        ((n1 - j - 1) / (i - j));
                    int remainingCount =
                        count[j + (n1 - j - 1) % (i - j)] - count[j];
                    return (previousCount + patternCount + remainingCount) / n2;
                }
            }
        }

        return count[n1 - 1] / n2;
    }
};