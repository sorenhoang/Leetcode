class Solution
{
public:
    static int array_method(int n, int modP, vector<int> &nums, int p)
    {
        int pos[100000];
        fill(pos, pos + p, INT_MAX);
        pos[0] = -1;
        int len = n, sumP = 0;
        for (int i = 0; i < n; i++)
        {
            sumP = (sumP + nums[i]) % p;
            int y = (sumP - modP + p) % p;
            if (pos[y] != INT_MAX)
                len = min(len, i - pos[y]);
            pos[sumP] = i;
        }
        return (len == n) ? -1 : len;
    }
    static int minSubarray(vector<int> &nums, int p)
    {
        const int n = nums.size();
        long long modP = accumulate(nums.begin(), nums.end(), 0LL) % p;

        //    cout<<modP<<endl;
        if (modP == 0)
            return 0;
        int sz = min(n, p);

        // hashmap version just comment the following line
        if (p <= n)
            return array_method(n, modP, nums, p);

        unordered_map<int, int> pos = {{0, -1}};
        pos.reserve(sz);

        int len = n, sumP = 0;
        for (int i = 0; i < n; i++)
        {
            sumP = (sumP + nums[i]) % p;
            int y = (sumP - modP + p) % p;
            if (pos.count(y))
                len = min(len, i - pos[y]);
            pos[sumP] = i;
        }
        return (len == n) ? -1 : len;
    }
};

auto init = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();