class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lower[26] = {0}, upper[26] = {0}, cnt = 0;
        for(char ch:word) {
            if(ch >= 'a' && ch <= 'z') {
                lower[ch - 'a'] = 1;
            }
            else {
                upper[ch - 'A'] = 1;
            }
        }
        
        for(int i=0; i<26; i++) {
            if(lower[i] && upper[i]) cnt++;
        }
        
        return cnt;
    }
};