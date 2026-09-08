class Solution {
public:
    string longestWord(vector<string>& words) {
        // STEP 1: Sort words alphabetically (A to Z)
        sort(words.begin(), words.end());
        
        // STEP 2: Memory Box with an empty string pre-loaded
        unordered_set<string> st = {""};
        
        string longest = "";
        
        // STEP 3: Loop through every word
        for (int i = 0; i < words.size(); i++) {
            // Cut off the last letter to find the prefix
            string prefix = words[i].substr(0, words[i].size() - 1);
            
            // Is the prefix inside our Memory Box?
            if (st.find(prefix) != st.end()) {
                // YES! Add the full word to the box
                st.insert(words[i]);
                
                // If this word is STRONGER (longer) than our current best, save it!
                if (words[i].size() > longest.size()) {
                    longest = words[i];
                }
            }
        }
        
        return longest; // Return the champion word! 🏆
    }
};