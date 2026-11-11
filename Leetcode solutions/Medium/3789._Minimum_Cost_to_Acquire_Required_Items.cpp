
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        
        long long both = 1LL * max(need1, need2) * costBoth;

        long long separate = 1LL * need1 * cost1 
                           + 1LL * need2 * cost2;

        long long common = min(need1, need2);

        long long mixed = 1LL * common * costBoth
                        + 1LL * (need1 - common) * cost1
                        + 1LL * (need2 - common) * cost2;

        return min({both, separate, mixed});
    }
};
