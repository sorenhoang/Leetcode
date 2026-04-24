#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    long long maximumPoints(vector<int> &enemyEnergies, int currentEnergy)
    {
        long long sum = accumulate(enemyEnergies.begin(), enemyEnergies.end(), 0ll);
        int minE = *(min_element(enemyEnergies.begin(), enemyEnergies.end()));

        return currentEnergy < minE ? 0 : (sum + currentEnergy) / minE - 1;
    }
};
