class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        // If the array is alphabetically sorted, the first and last elements will differ the most in prefix, 
        // so comparing just these two is enough.
        string ans = "";
        
        sort(strs.begin(), strs.end());
        
        int len = strs.size();
        
        string first = strs[0], last = strs[len-1];

        for(int i=0; i<min(first.size(), last.size()); i++) {
            if(first[i] != last[i]) return ans;
            ans += first[i];
        }

        return ans;
    }
};