class Solution {
public:
    unordered_set<string> st;
    
    vector<string> solve(string &s) {
        if(s.empty()) return {""};
        
        vector<string> res;
        
        for(int i = 1; i <= s.size(); i++) {
            
            string curr = s.substr(0, i);
            
            if(st.count(curr)) {
                string remainingWord = s.substr(i);
                
                vector<string> remainingRes = solve(remainingWord);
                
                for(string& word : remainingRes) {
                    string temp = curr + (word.empty() ? "" : " ") + word;
                    res.push_back(temp);
                }
            }
        }
        
        return res;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(string& word : wordDict) st.insert(word);
        return solve(s);
    }
};