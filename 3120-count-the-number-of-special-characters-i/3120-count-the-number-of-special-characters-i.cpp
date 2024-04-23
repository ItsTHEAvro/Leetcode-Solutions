class Solution {
public:
    int numberOfSpecialChars(string word) {
        int lower[26] = {0}, upper[26] = {0}, cnt = 0;
        for(int i=0; i<word.size(); i++) {
            if(word[i] >= 'a' && word[i] <= 'z') {
                lower[word[i] - 'a'] = 1;
            }
            else {
                upper[word[i] - 'A'] = 1;
            }
        }
        
        for(int i=0; i<26; i++) {
            if(lower[i] && upper[i]) cnt++;
        }
        
        return cnt;
    }
};