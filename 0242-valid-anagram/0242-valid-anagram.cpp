class Solution {
private:
    map<char, int> mp;
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        for(char&c:s) mp[c]++;
        for(char&c:t) mp[c]--;
        for(auto&it:mp) {
            if(it.second!=0) return false;
        }
        return true;
    }
};