class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = numBottles;
        
        while(numBottles >= numExchange)
        {
            int rem = numBottles % numExchange;
            numBottles /= numExchange;
            cnt += numBottles;
            numBottles += rem;
        }
        
        return cnt;
    }
};