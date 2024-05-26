class Solution {
public:
    const int MOD = 1000000000 + 7;
    
    int checkRecord(int n) {
        // Base case
        vector<vector<int>> previousDay(2, vector<int>(3, 1));
        
        // Iterate for each day
        for(int i = 1; i <= n; i++) {
            
            // Calculations for current day
            vector<vector<int>> currentDay(2, vector<int>(3, 0));
            
            // The student was absent ('A') for strictly fewer than 2 days total
            for(int A = 0; A < 2; A++) {
                
                // The student was never late ('L') for 3 or more consecutive days
                for(int L = 0; L < 3; L++) {
                    
                    // Pick P
                    currentDay[A][L] += previousDay[A][2];
                    currentDay[A][L] %= MOD;
                    
                    if(A > 0) {
                        // Pick A
                        currentDay[A][L] += previousDay[A-1][2];
                        currentDay[A][L] %= MOD;
                    }
                    
                    if(L > 0) {
                        // Pick L
                        currentDay[A][L] += previousDay[A][L-1];
                        currentDay[A][L] %= MOD;
                    }
                }
            }
            
            // Current day becomes previous day
            previousDay = currentDay;
        }
        
        return previousDay[1][2];
    }    
};