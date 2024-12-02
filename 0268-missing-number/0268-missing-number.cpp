class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int len = nums.size();
        
        vector<int> arr(len+1, 0);
        
        for(int num:nums) arr[num] = 1;
        
        for(int i=0; i<=len; i++) {
            if(arr[i] == 0) return i;
        }
        
        return -1;
    }
};