class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        int i=0;
        
        sort(happiness.rbegin(), happiness.rend());
        
        while(k--) {
            ans += max(happiness[i] - i, 0);
            i++;
        }
        
        return ans;
    }
};