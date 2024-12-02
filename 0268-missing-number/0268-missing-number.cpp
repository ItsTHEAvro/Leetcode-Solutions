class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), i = 0;
        
        for(int num:nums) {
            n ^= num;
            n ^= i;
            i++;
        }
        
        return n;
    }
};