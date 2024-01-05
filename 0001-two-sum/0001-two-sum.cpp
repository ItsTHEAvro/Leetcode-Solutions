class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> vp;
        for(int i=0; i<nums.size(); i++) vp.push_back({nums[i], i});
        sort(vp.begin(), vp.end());
        int lo=0, hi = vp.size()-1;
        vector<int> ans;
        while(lo<=hi) {
            if(vp[lo].first+vp[hi].first==target) {
                ans.push_back(vp[lo].second);
                ans.push_back(vp[hi].second);
                break;
            } else if(vp[lo].first+vp[hi].first>target) hi--;
            else lo++;
        }
        
        return ans;
    }
};