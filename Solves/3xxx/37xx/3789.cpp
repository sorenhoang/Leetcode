class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        int mneed = min(need1, need2);
        cost1 = min(cost1, costBoth);
        cost2 = min(cost2, costBoth);
        costBoth = min(costBoth, cost1 + cost2);
        return 1ll * costBoth * mneed + 1ll * cost1 * (need1 - mneed) + 1ll * cost2 * (need2 - mneed);
    }
};
