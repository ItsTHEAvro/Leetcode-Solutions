class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;
        
        for(int price : prices) {
            if(minPrice > price) minPrice = price;
            int profit = price - minPrice;
            if(profit > maxProfit) maxProfit = profit;
        }
        
        return maxProfit;
    }
};