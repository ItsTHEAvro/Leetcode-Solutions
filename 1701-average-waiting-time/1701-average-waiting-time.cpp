class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        /*
        cur = the current time
        t = customer arrival time
        d = time needed to prepare
        
        for each customer,
            start preparing for order at max(cur, t)
                finish his order at max(cur, t) + d
                    waiting period max(cur, t) + d - t
        */
        
        double totalWait = 0, cur = 0;
        
        for (const vector<int>& customer: customers) {
            int t = customer[0];
            int d = customer[1];
            
            cur = max(cur, 1.0 * t) + d;
            totalWait += cur - t;
        }
        
        return totalWait / customers.size();
    }
};