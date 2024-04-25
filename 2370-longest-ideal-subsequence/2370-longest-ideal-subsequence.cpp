class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        
        int a[26] = {0};
        
        int res = 0;
        
        for(int i=0; i<n; i++) {
            int curr = s[i] - 'a';
            int l = max(0, curr-k);
            int r = min(25, curr+k);
            
            int tmpMax = 0;
            for(int j=l; j<= r; j++) {
                tmpMax = max(tmpMax, a[j]);
            }
            
            a[curr] = max(a[curr], tmpMax+1);
            res = max(res, a[curr]);
        }
        
        return res;
    }
};