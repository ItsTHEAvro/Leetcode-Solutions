class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int res = 0, odd = 0;
        
        // Three pointer sliding window        
        // Shift right pointer
        for(int r = 0, l = 0, m = 0; r<nums.size(); r++) {
            
            // If encountered number is odd, increment odd
            if(nums[r]&1) {
                odd++;
            }
            
            // If odd > k shift left pointer to the point where odd is not greater than k
            while(odd > k) {
                if(nums[l]&1) {
                    odd--;
                }
                
                l++;
                m = l;
            }
            
            // If odd == k move the middle pointer to the first odd number in the window and increase count
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