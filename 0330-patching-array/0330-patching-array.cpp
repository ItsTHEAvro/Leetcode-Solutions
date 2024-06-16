class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int patch = 0, i = 0;
        long maxReach = 0;
        
        while(n > maxReach) {
            if(nums.size() > i && nums[i] <= maxReach + 1) {
                maxReach += nums[i];
                i++;
            } else {
                maxReach += (maxReach + 1);
                patch++;
            }
        }
        
        return patch;
    }
};