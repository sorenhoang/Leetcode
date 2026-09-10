class Solution {
public:
    int beautySum(string s) {

        int n = s.size();
        int sumOfBeauty = 0;

        for ( int i=0; i<n; i++ ) {
            for ( int j=i; j<n; j++ ) {
                vector<int> freq(26, 0);
                for ( int k=i; k<=j; k++ ) {
                    freq[s[k] - 'a']++;
                }
                int maxi = INT_MIN, mini = INT_MAX;
                for ( int i=0; i<26; i++ ) {
                    if (freq[i] == 0 ) continue; 
                    maxi = max(maxi, freq[i]);
                    mini = min(mini, freq[i]);
                }
                sumOfBeauty += (maxi - mini);
            }
        }

        return sumOfBeauty;

    }
};