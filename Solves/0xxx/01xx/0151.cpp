#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> words = split(s, ' ');
        reverse(words.begin(), words.end());
        string result;
        for (auto &word : words)
        {
            result += word + " ";
        }
        result = result.substr(0, result.size() - 1); // Remove trailing space
        return result;
    }

    vector<string> split(const string &s, char delimiter)
    {
        vector<string> tokens;
        string token = "";
        for (auto c : s)
        {
            if (c == delimiter)
            {
                if (!token.empty())
                {
                    tokens.push_back(token);
                }
                token = "";
            }
            else
            {
                token += c;
            }
        }
        if (!token.empty())
        {
            tokens.push_back(token);
        }
        return tokens;
    }
};

int main()
{
    Solution sol;
    string s = "  hello  world  ";
    cout << sol.reverseWords(s) << endl; // Output: "s'teL ekat edoCteeL tsetnoc"
    return 0;
}