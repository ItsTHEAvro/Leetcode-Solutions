class Solution {
public:
    int numSteps(string s) {
        int n = s.size(), res = 0, carry = 0;
        
        for (int i = n-1; i > 0; i--) {
            res++;
            if (s[i] - '0' + carry == 1) {
                carry = 1;
                res++;
            }
        }
        
        return res + carry;
    }
};