class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0, odd = 0;
        int l = 0, m = 0, r = 0;
        
        for(; r<nums.size(); r++) {
            if(nums[r]&1) {
                odd++;
            }
            
            while(odd > k) {
                if(nums[l]&1) {
                    odd--;
                }
                
                l++;
                m = l;
            }
            
            if(odd == k) {
                while(!(nums[m]&1)) {
                    m++;
                }
                
                res += (m - l + 1);
            }
        }
        
        return res;
    }
};