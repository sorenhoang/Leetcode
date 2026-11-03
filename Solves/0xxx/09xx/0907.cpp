class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int mod = 1e9 + 7;
        stack<int> st;
        int n = arr.size();
        vector<int> l(n, 0);

        long long ans = 0;

        for (int i = 0; i < arr.size(); ++i) {
            while (st.size() && arr[i] < arr[st.top()]) {
                st.pop();
            }

            l[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = arr.size() - 1; i >= 0; --i) {
            while (st.size() && arr[i] <= arr[st.top()]) {
                st.pop();
            }

            int r = st.empty() ? n : st.top();
            st.push(i);

            ans = (ans + 1ll * (i - l[i]) * (r - i) * arr[i]) % mod;
        }

        return ans;
    }
};
