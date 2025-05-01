class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> freq(26, 0);
        for(auto&c:s) freq[c-'a']++;
        int cnt = freq[s[0]-'a'];
        for(auto&c:freq) {
            if(c!=0 && c!=cnt) return false;
        }
        return true;
    }
};