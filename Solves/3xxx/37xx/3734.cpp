class Solution {
public:
    string buildPalindrome(const string& half, char middle) {
        string result = half;

        if (middle != 0) {
            result += middle;
        }

        for (int i = (int)half.size() - 1; i >= 0; --i) {
            result += half[i];
        }

        return result;
    }

    string smallestGreaterOrEqual(vector<int> count, const string& targetHalf) {
        int k = targetHalf.size();
        int matched = 0;

        while (matched < k && count[targetHalf[matched] - 'a'] > 0) {
            --count[targetHalf[matched] - 'a'];
            ++matched;
        }

        if (matched == k) {
            return targetHalf;
        }

        for (int pos = matched; pos >= 0; --pos) {
            if (pos < matched) {
                ++count[targetHalf[pos] - 'a'];
            }

            for (int c = targetHalf[pos] - 'a' + 1; c < 26; ++c) {
                if (count[c] == 0) continue;

                string result = targetHalf.substr(0, pos);
                result += char('a' + c);
                --count[c];

                for (int ch = 0; ch < 26; ++ch) {
                    result.append(count[ch], char('a' + ch));
                }

                return result;
            }
        }

        return "";
    }

    bool nextPermutation(string& half) {
        int n = half.size();
        int pivot = n - 2;

        while (pivot >= 0 && half[pivot] >= half[pivot + 1]) {
            --pivot;
        }

        if (pivot < 0) {
            return false;
        }

        int swapPos = n - 1;

        while (half[swapPos] <= half[pivot]) {
            --swapPos;
        }

        swap(half[pivot], half[swapPos]);

        reverse(half.begin() + pivot + 1, half.end());

        return true;
    }

    string lexPalindromicPermutation(string s, string target) {
        vector<int> frequency(26, 0);

        for (char ch : s) {
            ++frequency[ch - 'a'];
        }

        char middle = 0;
        int oddCount = 0;

        for (int c = 0; c < 26; ++c) {
            if (frequency[c] % 2 == 1) {
                ++oddCount;
                middle = char('a' + c);
            }
        }

        if (oddCount > 1) {
            return "";
        }

        vector<int> halfCount(26, 0);

        for (int c = 0; c < 26; ++c) {
            halfCount[c] = frequency[c] / 2;
        }

        int k = s.size() / 2;
        string targetHalf = target.substr(0, k);

        string half = smallestGreaterOrEqual(halfCount, targetHalf);

        if (half.empty() && k > 0) {
            return ""; 
        }

        string candidate = buildPalindrome(half, middle);

        if (candidate > target) {
            return candidate;
        }

        if (!nextPermutation(half)) {
            return "";
        }

        return buildPalindrome(half, middle);
    }
};