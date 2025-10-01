class Solution
{
public:
    vector<int> threeEqualParts(vector<int> &arr)
    {
        int tot = 0, lastElem = arr.size(), lmt = lastElem / 3, s1, s2, last,
            curr1 = 0, curr2 = 0, pos1 = 0, pos2 = 0, s1s[lmt], s2s[lmt];
        lastElem--;
        for (int i = 0; i <= lastElem; i++)
        {
            // finding a `1`
            if (arr[i])
            {
                tot++;
                // storing i in s1s if it is not full
                if (pos1 < lmt)
                    s1s[pos1++] = i;
                // storing i in s2s every 2 1s if it is not full
                if (pos2 < lmt && !(tot & 1))
                    s2s[pos2++] = i;
                // updating pointers every 3 1s
                if (!(tot % 3))
                {
                    last = i;
                    s1 = s1s[curr1++];
                    s2 = s2s[curr2++];
                }
            }
        }
        // edge case: no 1s
        if (!tot)
            return {0, lastElem};
        // exit case: can't form 3 groups with the same number of 1s
        if (tot % 3)
            return {-1, -1};
        // moving the pointer to the last 0 of the sequence
        int diff = lastElem - last;
        // updating s1 and s2, plus exit case: not enough 0s between either s1 and s2 or s2 and last
        s1 += diff;
        if (s1 >= s2)
            return {-1, -1};
        s2 += diff;
        if (s2 >= last)
            return {-1, -1};
        // updating curr1, curr2, last and tot to check the segment structure
        curr1 = s1, curr2 = s2, last = lastElem, tot /= 3;
        while (tot)
        {
            // checking if all the elements match
            if (arr[curr1] != arr[curr2] || arr[curr2] != arr[last])
                return {-1, -1};
            // updating variables for the next loop
            tot -= arr[curr1];
            curr1--, curr2--, last--;
        }
        // checking if the segments have the same structure
        return {s1, s2 + 1};
    }
};