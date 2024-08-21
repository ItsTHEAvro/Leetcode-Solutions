/*
Find the minium cost

Starting with the nth step what are my actions?
Return the minimum of updated cost[n-1], cost[n-2]

To update the costs:
for ith step:
    cost[i] = cost[i] + min(cost[i-1], cost[i-2]);

Base cases:
    cost[0] = 0

*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        const int n = cost.size();
        
        for(int i=2; i<n; i++) {
            cost[i] = cost[i] + min(cost[i-1], cost[i-2]);
        }
        
        return min(cost[n-1], cost[n-2]);
        
    }
};