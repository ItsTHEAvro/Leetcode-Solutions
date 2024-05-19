class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int> delta;
        long long res = 0;
        
        for(int i=0; i<n; i++) {
            delta.push_back((nums[i]^k) - nums[i]);
            res += nums[i];
        };
        
        sort(delta.rbegin(), delta.rend());
        
        for(int i=0; i<n; i+=2) {
            if(i == n-1) break;
            long long temp = delta[i] + delta[i+1];
            if(temp <= 0) break;
            res += temp;
        }
        
        return res;
    }
};