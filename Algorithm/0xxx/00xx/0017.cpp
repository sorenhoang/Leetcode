class Solution {
private:
    vector<string> letters{"abc", "def",  "ghi", "jkl",
                           "mno", "pqrs", "tuv", "wxyz"};

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        result.clear();

        if (!digits.size())
            return result;

        result.push_back("");

        for (auto c : digits) {
            int digit = c - '2';
            vector<string> temp;
            for (auto item : result) {
                for (char ch : letters[digit]) {
                    temp.push_back(item + ch);
                }
            }
            result = temp;
        }

        return result;
    }
};