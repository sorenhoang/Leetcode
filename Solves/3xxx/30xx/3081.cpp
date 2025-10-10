#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string minimizeStringValue(string s)
    {
        vector<int> freq(26, 0);
        vector<int> avail(26, 0);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        int cnt = 0;
        for (char c : s)
        {
            if (c == '?')
                cnt++;
            else
                freq[c - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            pq.push({freq[i], i});
        }
        while (cnt--)
        {
            auto id = pq.top();
            pq.pop();
            int f = id.first;
            int c = id.second;
            avail[c]++;
            f++;
            pq.push({f, c});
        }
        string result;
        for (auto c : s)
        {
            if (c == '?')
            {
                for (int i = 0; i < 26; i++)
                {
                    if (avail[i] > 0)
                    {
                        result.push_back((char)('a' + i));
                        avail[i]--;
                        break;
                    }
                }
            }
            else
            {
                result.push_back(c);
            }
        }

        return result;
    }
};

int main()
{
    Solution sol;
    string s = "a?a?";
    cout << sol.minimizeStringValue(s) << endl; // Output: "aabaa"
    return 0;
}