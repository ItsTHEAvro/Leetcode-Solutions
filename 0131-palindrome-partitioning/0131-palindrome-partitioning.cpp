class Solution {
public:
    bool isPalindrome(string str, int l, int r) {
        while(l <= r) {
            if(str[l] != str[r]) {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    
    void palindromePartition(int startIndex, vector<string>& partitions, vector<vector<string>>& res, string str) {
        int n = str.size();
        
        if(startIndex == n) {
            res.push_back(partitions);
            return;
        }
        
        for(int i = startIndex; i < n; i++) {
            if(isPalindrome(str, startIndex, i)) {
                // Saving partitions
                partitions.push_back(str.substr(startIndex, i - startIndex + 1));
                
                // Recursion
                palindromePartition(i+1, partitions, res, str);
                
                // Backtracking
                partitions.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> partitions;
        
        palindromePartition(0, partitions, res, s);
        
        return res;
    }
};