class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int prefix[n], suffix[n];
        
        prefix[0] = 1;
        suffix[n-1] = 1;
        
        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] * nums[i-1];
            suffix[n-i-1] = suffix[n-i] * nums[n-i];
        }
                
        vector<int> ans;
        
        for(int i=0; i<n; i++) {
            ans.push_back(prefix[i] * suffix[i]);
        }
        
        return ans;
    }
};