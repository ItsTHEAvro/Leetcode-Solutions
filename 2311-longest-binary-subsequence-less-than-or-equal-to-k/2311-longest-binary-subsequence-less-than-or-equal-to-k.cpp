class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        long long curr = 0;
        int count = 0;
        long long pow2 = 1;

        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '0') {
                count++;
            } else {
                if(curr + pow2 <= k) {
                    curr += pow2;
                    count++;
                }
            }

            if(pow2 <= k / 2) {
                pow2 *= 2;
            } else {
                pow2 = k + 1;
            }
        }
        return count;
    }
};