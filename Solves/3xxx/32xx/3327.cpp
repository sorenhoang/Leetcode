#include <bits/stdc++.h>

using namespace std;

class Solution
{

private:
    vector<vector<int>> adj;
    vector<vector<int>> idx;
    int stId;
    string t;

public:
    vector<bool> findAnswer(vector<int> &parent, string s)
    {
        int n = parent.size();
        t = "^";
        idx.resize(n);
        adj.resize(n);
        stId = 0;

        for (int i = 1; i < n; ++i)
        {
            adj[parent[i]].push_back(i);
        }

        dfs(0, s);
        t += "#$";

        vector<int> p = manacher_init(t);
        vector<bool> answer(n, false);

        for (int i = 0; i < n; ++i)
        {
            int l = (idx[i][0] + 1) * 2;
            int r = (idx[i][1]) * 2;
            int mid = (l + r) / 2;
            if (p[mid] * 2 >= (r - l))
            {
                answer[i] = true;
            }
        }

        return answer;
    }

    void dfs(int u, string& s)
    {
        idx[u].push_back(stId);
        for (int v : adj[u])
        {
            dfs(v, s);
        }
        t += "#";
        t += s[u];
        idx[u].push_back(++stId);
    }

    vector<int> manacher_init(string& s)
    {
        int n = s.size();
        vector<int> p(n, 0);
        int R = 0;
        int C = 0;

        for (int i = 1; i < n; ++i)
        {
            if (i < R)
            {
                int minor = C * 2 - i;
                p[i] = min(R - i, p[minor]);
            }
            while (i - 1 - p[i] >= 0 && i + 1 + p[i] < n && s[i + 1 + p[i]] == s[i - 1 - p[i]])
            {
                p[i]++;
            }
            if (i + p[i] > R)
            {
                C = i;
                R = i + p[i];
            }
        }
        return p;
    }
};

int main()
{
    // Input: parent = [-1,0,0,1,1,2], s = "aababa"
    vector<int> parent{-1, 0, 0, 1, 1, 2};
    string s = "aababa";
    vector<bool> answer = Solution().findAnswer(parent, s);
    for (auto value : answer)
    {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}