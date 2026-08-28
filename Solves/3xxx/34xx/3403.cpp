class Solution {
public:
    string answerString(string word, int numFriends) {
        vector<string> strs;
        int n = word.size();

        if(numFriends == 1)
        {
            return word;
        }

        for (int i = 0; i < n; ++i) {
            if(i>= numFriends-1) {
                string temp = word.substr(i, n-i);
                strs.push_back(temp);
            }
            else{
                string temp = word.substr(i, n-numFriends+1);
                strs.push_back(temp);
            }
        }

        sort(strs.begin(), strs.end());
        return strs.back();
    }
};