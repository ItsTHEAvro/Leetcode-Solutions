class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        nums.push_back(nums[0]);
        for(int num:nums) cout << num << " ";
        int diff = 0;
        for(int i=1; i<nums.size(); i++) {
            diff = max(diff, abs(nums[i] - nums[i-1]));
        }
        return diff;
    }
};