class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<pair<int, int>> numsWithIndex(n);
        vector<bool> taken(n, false);
        vector<int> result;
        
        for(int i=0;i<n;i++) numsWithIndex[i] = {nums[i], i};
		
		sort(numsWithIndex.begin(), numsWithIndex.end(), greater<pair<int, int>>());
        
		for(int i=0;i<k;i++) taken[numsWithIndex[i].second] = true;
        
		for(int i=0;i<n;i++) {
            if(taken[i]) result.push_back(nums[i]);
        }

        return result;
    }
};