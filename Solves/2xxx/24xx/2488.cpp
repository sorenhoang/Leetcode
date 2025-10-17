#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
class Solution
{
private:
    struct SegmentTree
    {
        int freq[MAXN];
        SegmentTree()
        {
            memset(freq, 0, sizeof(freq));
        }
        void update(int idx, int val)
        {
            for (; idx < MAXN; idx += idx & -idx)
                freq[idx] += val;
        }
        int query(int idx)
        {
            int sum = 0;
            for (; idx > 0; idx -= idx & -idx)
                sum += freq[idx];
            return sum;
        }
    };

public:
    int countSubarrays(vector<int> &nums, int k)
    {
        long long upperRes = CountMed(nums, k);
        cout << upperRes << endl;
        long long lowerRes = CountMed(nums, k - 1);
        cout << lowerRes << endl;
        return upperRes - lowerRes;
    }

    long long CountMed(vector<int> nums, int lim)
    {
        SegmentTree T;

        long long ans = 0;
        int cur = 1e5 + 1;
        T.update(cur, 1);
        for (auto num : nums)
        {
            cur += (num <= lim) ? 1 : -1;
            ans += T.query(cur);
            T.update(cur, 1);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {4, 1, 3, 2};
    int k = 1;
    int result = sol.countSubarrays(nums, k);
    cout << "Output: " << result << endl;
    return 0;
}