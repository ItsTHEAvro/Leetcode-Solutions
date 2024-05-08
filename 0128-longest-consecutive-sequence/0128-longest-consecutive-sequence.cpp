class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        if(n == 0) return 0;
        
        sort(nums.begin(), nums.end());
        
        int ans = INT_MIN, curr = 1;
        
        for(int i=0; i<n-1; i++) {
            if(nums[i+1] == nums[i]) {
                continue;
            } else if(nums[i+1] - nums[i] > 1) {
                ans = max(ans, curr);
                curr = 1;
            } else {
                curr++;
            }
        }
        
        return max(ans, curr);
    }
};