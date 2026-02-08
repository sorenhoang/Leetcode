class Solution
{
private:
    struct FenweekTree
    {
        /* data */
        int n;
        vector<int> dx;
        FenweekTree(int size)
        {
            n = size;
            dx.resize(size + 2, 0);
        }

        void update(int x, int delta)
        {
            for (int i = x; i <= n; i += i & -i)
            {
                dx[i] = max(dx[i], delta);
            }
        }

        int get(int x)
        {
            int res = 0;
            for (int i = x; i > 0; i -= i & -i)
            {
                res = max(res, dx[i]);
            }
            return res;
        }
    };

public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        int offset = 5e4 + 1;
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        int lim = 0;
        for (auto &interval : intervals)
        {
            interval[0] += offset;
            interval[1] += offset;
            lim = max(lim, interval[1]);
        }

        FenweekTree fenweekTree(lim + 2);
        for (auto interval : intervals)
        {
            int start = interval[0];
            int end = interval[1];
            int currMax = fenweekTree.get(start) + 1;
            fenweekTree.update(end, currMax);
        }
        return n - fenweekTree.get(lim);
    }
};