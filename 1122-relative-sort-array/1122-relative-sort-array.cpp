class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {        
        
        vector<int> freq(1001);
        
        for(int i = 0; i < arr1.size(); i++) {
            freq[arr1[i]]++;
        }
        
        vector<int> ans;
        
        for(int i = 0; i < arr2.size(); i++) {
            while(freq[arr2[i]]--) {
                ans.push_back(arr2[i]);
            }
        }
        
        for(int i = 0; i < freq.size(); i++) {
            while(freq[i]-- > 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};