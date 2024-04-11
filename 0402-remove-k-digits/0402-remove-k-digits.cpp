class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        
        for(char digit:num) {
            while(!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }
        
        while(!st.empty() && k>0) {
            st.pop();
            k--;
        }
        
        string res;
        
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        
        int i=0;
        while(res[i]=='0') i++;
        res.erase(0, i);
        
        return (res=="")?"0":res;
    }
};