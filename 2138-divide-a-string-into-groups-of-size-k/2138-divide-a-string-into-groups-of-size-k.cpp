class Solution {
public:
    vector<string> divideString(string s, int k, char fill) 
    {
        int n = s.size();
        vector<string> res;

        for(int i=0; i<n; i+=k) {
            res.push_back(s.substr(i,k));
        }

        if(res.back().size() == k) {
            return res;
        }

        for(int i = res.back().size(); i<k; i++) {
            res.back() += fill;
        }

        return res;
    }
};