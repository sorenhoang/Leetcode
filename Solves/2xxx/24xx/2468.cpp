#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> splitMessage(string message, int limit)
    {
        int parts = -1;
        for (int i = 1; i <= message.size(); ++i)
        {
            if (check(i, limit, message.size()))
            {
                parts = i;
                break;
            }
        }
        if (parts == -1)
            return {};
        vector<string> result;
        int index = 0;
        cout << "Parts: " << parts << endl;
        for (int i = 1; i <= parts; ++i)
        {
            int digits = to_string(parts).size();
            int current_digits = to_string(i).size();
            int suffix_length = current_digits + digits + 3; // '<i/parts>'
            int available_length = limit - suffix_length;
            if (available_length <= 0)
                return {};
            string part = message.substr(index, available_length);
            index += available_length;
            part += "<" + to_string(i) + "/" + to_string(parts) + ">";
            if (part.size() > limit)
            {
                return {};
            }
            result.push_back(part);
        }

        return result;
    }

    bool check(int parts, int limit, int message_length)
    {
        int digits = to_string(parts).size();
        int total_length = 0;
        for (int i = 1; i <= parts; i = i * 10)
        {
            int cur = min(parts - i + 1, i * 9);
            int current_digits = to_string(i).size();
            int suffix_length = current_digits + digits + 3; // '<i/parts>'
            int available_length = limit - suffix_length;
            if (available_length <= 0)
                return false;
            total_length += available_length * (cur);
        }
        return total_length >= message_length;
    }
};

int main()
{
    Solution sol;
    string message = "abbababbbaaa aabaa a";
    int limit = 8;
    vector<string> res = sol.splitMessage(message, limit);
    for (auto str : res)
    {
        cout << str << endl;
    }
    return 0;
}