class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        
        if(n <= 4) {
            return 0;
        }
        
        sort(nums.begin(), nums.end());
        
        int d = nums[n-1] - nums[3];
        d = min(d, nums[n-4] - nums[0]);
        d = min(d, nums[n-2] - nums[2]);
        d = min(d, nums[n-3] - nums[1]);
        
        return d;
    }
};