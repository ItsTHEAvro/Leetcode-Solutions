class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0)  return 0;
        
        // Each child must have at least one candy.
        vector<int> candies(n, 1);
        
        // children with a higher rating get more candies than their left neighbors.
        for (int i = 1; i < n; ++i) {
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }
        
        // If this child's rating is higher than their right neighbor's, they need more candy than them.
        // We also need to make sure we don't give them less than what the left-neighbor rule already decided.
        // So, they get the bigger of these two: 
        // what they have now (from the left-pass) or 
        // one more than their right neighbor.
        for (int i = n - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }
        
        int ans = 0;
        for (int count : candies) ans += count;
        return ans;
    }
};