class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int count = 0, minVal = -1; 

        for(int num:nums) {
            if(count == 0 || (num - minVal) > k) {
                count++;
                minVal = num;
            }
        }

        return count;
    }
};