#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    bool hasAllCodes(string s, int k)
    {
        unordered_set<string> st;

        string tmp = "";
        for (auto c : s)
        {
            tmp += c;
            if (tmp.size() > k)
            {
                tmp = tmp.substr(1);
            }
            if (tmp.size() == k)
            {
                st.insert(tmp);
            }
        }

        return st.size() == (1 << k);
    }
};

int main()
{
    string s = "00110110";
    int k = 2;
    cout << Solution().hasAllCodes(s, k) << endl;

    return 0;
}