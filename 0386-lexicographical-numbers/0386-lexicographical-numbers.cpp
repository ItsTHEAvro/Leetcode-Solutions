class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> s;
        for(int i=1; i<=n; i++) s.push_back(to_string(i));
        sort(s.begin(), s.end());
        vector<int> res;
        for(const string& str:s) res.push_back(stoi(str));
        return res;
    }
};