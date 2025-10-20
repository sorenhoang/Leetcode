class Solution
{
public:
    vector<int> memLeak(int memory1, int memory2)
    {
        int t = 1;
        while (max(memory1, memory2) >= t)
        {
            if (memory1 < memory2)
                memory2 -= t;
            else
                memory1 -= t;
            ++t;
        }
        return {t, memory1, memory2};
    }
};