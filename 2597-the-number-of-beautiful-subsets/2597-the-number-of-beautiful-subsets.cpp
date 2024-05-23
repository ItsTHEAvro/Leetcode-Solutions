class Solution {
public:
    int cnt;
    int K;
    
    void solve(int i, vector<int>& nums, unordered_map<int, int>& mp) {
        if(i >= nums.size()) {
            cnt++;
            return;
        }
        
        // Not take
        solve(i + 1, nums, mp);
        
        // Take
        if(!mp[nums[i] - K] && !mp[nums[i] + K]) {
            mp[nums[i]]++;
            solve(i + 1, nums, mp);
            mp[nums[i]]--;
        }
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        cnt = 0;
        K = k;
        
        unordered_map<int, int> mp;
        
        solve(0, nums, mp);
        
        return cnt - 1; // To exclude empty subset
    }
};