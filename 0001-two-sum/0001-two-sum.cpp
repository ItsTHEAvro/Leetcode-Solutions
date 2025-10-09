class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for(int i=0; i < nums.size(); i++) mp[nums[i]] = i;
        
        for(int i=0; i < nums.size(); i++) {
            int s = target - nums[i];
            if((mp.find(s) != mp.end()) && (mp[s] != i)) return {i, mp[s]}; 
        }

        return {};
    }
};