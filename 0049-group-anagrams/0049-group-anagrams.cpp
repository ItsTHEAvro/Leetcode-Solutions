class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<string, vector<string>> mp;
        for(auto&it:strs) {
            string word = it;
            sort(word.begin(), word.end());
            mp[word].push_back(it);
        }
        
        for(auto&it:mp) {
            vector<string> tmp;
            for(auto&str:it.second) {
                tmp.push_back(str);
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};