class Solution {
public:
    string reversePrefix(string word, char ch) {
        if(word.find(ch) == string::npos) return word;
        
        string st = "";
        
        int i=0;
        
        for(; i<word.size(); i++) {
            st += word[i];
            if(word[i] == ch) {
                i++;
                break;
            };
        }
        
        reverse(st.begin(), st.end());
        
        for(;i<word.size(); i++) {
            st += word[i];
        }
        
        return st;
    }
};