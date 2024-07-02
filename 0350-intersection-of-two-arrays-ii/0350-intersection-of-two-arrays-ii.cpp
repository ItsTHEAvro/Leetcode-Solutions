class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>freq;
        
        vector<int> res;
        
        for(const int &num : nums1){
            freq[num]++;
        }
        
        for(const int &num : nums2){
            if (freq[num] > 0){
                freq[num]--; 
                res.push_back(num);
            }
        }
        
        return res;
    }
};