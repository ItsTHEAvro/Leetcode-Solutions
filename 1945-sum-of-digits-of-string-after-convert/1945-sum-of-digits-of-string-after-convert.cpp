class Solution {
public:
    int getLucky(string s, int k) {
        string str;
        for(const char ch:s) {
            str += to_string(ch - 'a' + 1);
        }

        while(k--) {
            int temp = 0;
            for (const char ch:str) temp += ch - '0';
            str = to_string(temp); 
        }
        
        return stoi(str);
    }
};