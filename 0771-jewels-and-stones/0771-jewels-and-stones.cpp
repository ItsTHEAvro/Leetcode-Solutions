class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int cnt = 0;
        for(const char j:jewels) {
            for(const char s:stones) {
                if(j == s) cnt++;
            }
        }
        
        return cnt;
    }
};