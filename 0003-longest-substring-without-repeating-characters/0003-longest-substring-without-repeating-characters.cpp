class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0, r = 0, maxLen = 0;
        unordered_set<char> charset;
        for(r = 0; r < n; r++) {
            if(charset.count(s[r]) == 0) {
                charset.insert(s[r]);
                maxLen = max(maxLen, (r-l+1));
            } else {
                while(charset.count(s[r])) {
                    charset.erase(s[l]);
                    l++;
                }
                charset.insert(s[r]);
            }
        }
        return maxLen;
    }
};