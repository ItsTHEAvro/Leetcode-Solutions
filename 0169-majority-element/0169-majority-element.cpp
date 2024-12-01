class Solution {
public:
    int majorityElement(vector<int>& nums) {
        set<int> st;
        
        for(int num : nums) st.insert(num);
        
        int mxCount = 0;
        int res = INT_MIN;
        
        for(int num:st) {
            int cnt = count(nums.begin(), nums.end(), num);
            if(mxCount < cnt) {
                mxCount = max(mxCount, cnt);
                res = num;
            }
        }
        
        return res;
    }
};