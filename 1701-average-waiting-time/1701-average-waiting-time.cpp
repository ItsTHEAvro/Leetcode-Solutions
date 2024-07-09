class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {       
        double totalWait = 0, cur = 0;
        
        for (const vector<int>& customer: customers) {         
            cur = max(cur, 1.0 * customer[0]) + customer[1];
            totalWait += cur - customer[0];
        }
        
        return totalWait / customers.size();
    }
};