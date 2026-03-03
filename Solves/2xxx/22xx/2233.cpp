#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    int maximumProduct(vector<int> &nums, int k)
    {
        int mod = 1e9 + 7;
        priority_queue<int> heap;
        for (int num : nums)
        {
            heap.push(-num);
        }

        while (k--)
        {
            int c = heap.top();
            heap.pop();
            heap.push(c - 1);
        }

        int res = 1;
        while (heap.size())
        {
            int c = -heap.top();
            heap.pop();
            res = 1ll * res * c % mod;
        }
        return res;
    }
};