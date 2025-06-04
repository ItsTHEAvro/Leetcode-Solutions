class Solution {
public:
    string answerString(string word, int numFriends) {
        // word length is 1, return the word itself
        if (numFriends == 1) return word;
    
        // If one part is maximized, the other numFriends - 1 parts can each be of length 1 
        // The total length would be (n - numFriends + 1) + (numFriends - 1)*1 = n
        int n = word.size(), longestPossibleSubstringLen = n - numFriends + 1;
        string ans = "";
        for(int i=0; i<n; i++) ans = max(ans, word.substr(i, longestPossibleSubstringLen));
        return ans;
    }
};