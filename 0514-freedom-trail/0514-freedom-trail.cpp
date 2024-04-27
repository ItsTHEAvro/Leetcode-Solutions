class Solution {
public:
    int memo[101][101];
      
    int solve(string& ring, string& key, int startIndex, int keyIndex) {
        int n = ring.length();
        
        if(keyIndex == key.length()) return 0;
        
        if(memo[startIndex][keyIndex] != -1) return memo[startIndex][keyIndex];
        
        int res = INT_MAX;
        
        for(int i=0; i<ring.length(); i++) {
            if(ring[i] == key[keyIndex]) {
                int steps = min(n-abs(i-startIndex), abs(i-startIndex)) + solve(ring, key, i, keyIndex+1) + 1;
                res = min(res, steps);
            }
        }
        
        return memo[startIndex][keyIndex] = res;
        
    }
    
    int findRotateSteps(string ring, string key) {
        memset(memo, -1, sizeof(memo));
        return solve(ring, key, 0, 0);
    }
};