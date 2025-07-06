class FindSumPairs
{
    vector<int> nums1, nums2;
    unordered_map<int, int> cnt2;

public:
    FindSumPairs(vector<int> &a, vector<int> &b) : nums1(a), nums2(b)
    {
        cnt2.reserve(nums2.size() * 2);
        for (int x : nums2)
            ++cnt2[x];
    }

    void add(int idx, int val)
    {
        int old = nums2[idx];
        auto it = cnt2.find(old);
        if (--it->second == 0)
            cnt2.erase(it);
        nums2[idx] = old + val;
        ++cnt2[nums2[idx]];
    }

    int count(int tot)
    {
        long long ans = 0;
        for (int x : nums1)
        {
            auto it = cnt2.find(tot - x);
            if (it != cnt2.end())
                ans += it->second;
        }
        return ans;
    }
};