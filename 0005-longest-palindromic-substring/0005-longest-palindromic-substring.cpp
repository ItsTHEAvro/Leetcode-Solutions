class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res = "";
        int resLen = 0;
        
        for(int i=0; i<n; i++) {
            // odd length
            int l = i;
            int r = i;
            while(((l >= 0) && (r < n)) && (s[l] == s[r])) {
                if((r - l + 1) > resLen) {
                    res = s.substr(l, (r - l + 1));
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }
            
            // even length
            l = i;
            r = i + 1;
            while(((l >= 0) && (r < n)) && (s[l] == s[r])) {
                if((r - l + 1) > resLen) {
                    res = s.substr(l, (r - l + 1));
                    resLen = r - l + 1;
                }
                l--;
                r++;
            }
        }
        
        return res;
    }
};