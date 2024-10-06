class Solution {
public:
    int strStr(string haystack, string needle) {

        int i = 0 , j = 0;
        int n = needle.size();
        int m = haystack.size();
        
        if(n > m) return -1;

        for(int i=0;i<m;i++)
        {
            int j, k = i;
            for(j=0;j<n && k<m;j++,k++)
            {
                if(haystack[k] != needle[j]) break;
            }
            if(j == n) return i;
        }
        return -1;
    }
};