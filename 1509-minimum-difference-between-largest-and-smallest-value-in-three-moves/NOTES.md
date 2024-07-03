```
nums = [1,5,0,10,14]

After sorting,
nums = [0,1,5,10,14]

Making 3 min elements equal to the 4th min element
nums = [10,10,10,10,14]
Current min = fourth element = nums[3] = 10
Current max = last element = nums[n-1] = 14
diff1 = nums[n-1] - nums[3] = 14 - 10 = 4

Making 3 max elements equal to the 4th max element
nums = [0,1,1,1,1]
Current min = first element = nums[0] = 0
Current max = fourth max element = nums[n-4] = 1
diff2 = nums[n-4] - nums[0] = 1 - 0 = 1

Making 1 max element equal to the 2nd max and 2 min elements equal to the 3rd min element
nums = [5,5,5,10,10]
Current min = third min element = nums[2]
Current max = second max element = nums[n-2]
diff3 = nums[n-2] - nums[2] = 10 - 5 = 5

Making 2 max elements equal to the 3rd max and 1 min element equal to the 2nd min element
nums = [1,1,5,5,5]
Current min = second min element = nums[1]
Current max = third max element = nums[n-3]
diff4 = nums[n-3] - nums[1] = 5 - 1 = 4

Result = min(diff1, diff2, diff3, diff4)
Result = min(4, 1, 5, 4) = 1
```

```cpp
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
```​
