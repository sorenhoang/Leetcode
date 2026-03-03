#include <bits/stdc++.h>
#define ll long long
#define nl '\n'
class Solution
{
public:
    int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues)
    {
        int n = aliceValues.size();
        // max heap  to sort stones based on the sum of values to Alice and Bob
        priority_queue<pair<int, int>> maxHeap;
        // Fill the heap with pairs of (sum of values, index)
        for (int i = 0; i < n; i++)
        {
            maxHeap.push({aliceValues[i] + bobValues[i], i});
            // heap will contain the sum of both alice and bob values,
            // sum of both will helps us to play the game optimally, both needs maximum score, so we play optimaly which is the maximum score
        }
        int aliceScore = 0, bobScore = 0;
        bool aliceTurn = true;

        while (!maxHeap.empty())
        {
            int index = maxHeap.top().second;
            maxHeap.pop();
            if (aliceTurn == true)
            {
                aliceScore += aliceValues[index]; // taking alice value
            }
            else
            {
                bobScore += bobValues[index];
            }
            aliceTurn = !aliceTurn;
            ; // next is bobs turn
        }
        if (aliceScore > bobScore)
            return 1;
        if (bobScore > aliceScore)
            return -1;
        return 0;
    }
};