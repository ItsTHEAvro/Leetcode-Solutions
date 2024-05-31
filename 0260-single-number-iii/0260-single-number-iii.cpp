class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long totalXor = 0;
        int n = nums.size();
        
        for(int i=0; i<n; i++) totalXor ^= nums[i];
        
        int mask = totalXor & -totalXor;
        
        int l = 0;
        int r = 0;
        
        for(int i=0; i<n; i++) {
            if(nums[i] & mask) l ^= nums[i];
            else r ^= nums[i];
        }
                   
        return {l, r};
    }
};