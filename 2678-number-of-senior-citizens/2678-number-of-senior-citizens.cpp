class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(const string detail : details) {
            if((detail[11] - '0') * 10 + (detail[12] - '0') > 60) cnt++;
        }
        
        return cnt;
    }
};