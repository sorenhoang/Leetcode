class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res;

        stack<int> st;
        for(int i = n-1 ;i >= 0; --i)
        {
            while(st.size() && temperatures[i] >= temperatures[st.top()])
            {
                st.pop();
            }
            int nextL = 0;
            if(!st.size()) nextL = 0;
            else nextL = st.top() - i;
            res.push_back(nextL);
            
            st.push(i);
        }

        reverse(res.begin(),res.end());

        return res;
    }
};