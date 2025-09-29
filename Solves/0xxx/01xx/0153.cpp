class Solution
{
public:
    int findMin(vector<int> &v)
    {
        int s = 0, e = v.size() - 1;
        while (s < e)
        {
            if (v[s] < v[e])
                return v[s];
            int mid = s + (e - s) / 2;
            if (v[mid] >= v[s])
            {
                s = mid + 1;
            }
            else
            {
                e = mid;
            }
        }
        return v[s];
    }
};