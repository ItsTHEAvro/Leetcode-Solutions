class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int l = 0, r = nums.size() - 1;
        
        while(l <= r) {
            if(nums[r] == -nums[l]) {
                return nums[r];
            } else if(nums[r] > -nums[l]) {
                r--;
            } else {
                l++;
            }
        }
        
        return -1;
    }
};