class Solution
{
public:
    string addSpaces(string s, vector<int> &spaces)
    {
        // for(int i=0;i<spaces.size();i++) {
        //     s.insert(s.begin()+spaces[i]+i,' ');
        // }
        // return s;
        unordered_set<int> set;
        for (int i = 0; i < spaces.size(); i++)
        {
            set.insert(spaces[i] + i);
        }
        string ans = "";
        int idx = 0;
        for (auto ch : s)
        {
            if (set.count(idx))
            {
                ans += " ";
                idx++;
            }
            ans += ch;
            idx++;
        }
        return ans;
    }
};