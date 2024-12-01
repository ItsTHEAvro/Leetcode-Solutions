class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> vp;
        
        for(int i=0; i<nums.size(); i++) {
            vp.push_back({nums[i], i});
        }
        
        sort(vp.begin(), vp.end());
        
        int l = 0, r = nums.size() - 1;
        
        while(l <= r) {
            long long tmp = vp[l].first + vp[r].first;
            if(tmp == target) break;
            else if(tmp > target) r--;
            else l++;
        }
        
        return {vp[l].second, vp[r].second};
        
    }
};
