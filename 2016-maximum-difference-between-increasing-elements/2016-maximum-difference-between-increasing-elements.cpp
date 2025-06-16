#include <vector>
#include <algorithm>

class Solution {
public:
    int maximumDifference(std::vector<int>& nums) {
        int n = nums.size();
        int max_diff = -1;
        int min_num = nums[0];

        for(int i=1; i < n; i++) {
            if(nums[i] > min_num) max_diff = max(max_diff, nums[i] - min_num);
            min_num = min(min_num, nums[i]);
        }

        return max_diff;
    }
};