class Solution {
public:
    int appendCharacters(string s, string t) {
        int index = 0;
        for (int i = 0; i <= t.size(); ++i)
        {
            while(index < s.size() && s[index] != t[i])
            {
                index++;
            }

            if(index == s.size()) return t.size() - i;
            index++;
        }

        return t.size();
    }
};
