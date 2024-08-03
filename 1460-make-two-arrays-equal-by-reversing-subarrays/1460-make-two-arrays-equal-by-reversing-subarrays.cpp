class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> mp;
        
        for(int i=0; i < target.size(); i++) {
            mp[target[i]]++;
            mp[arr[i]]--;
        }
        
        for(const auto item:mp) {
            if(item.second) {
                return false;
            }
        }
        
        return true;
    }
};