class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        
        vector<pair<int, int>> vp;
        for(int i = 0; i<n; i++) {
            vp.push_back({score[i], i});
        }
        
        sort(vp.rbegin(), vp.rend());
        
        vector<string> ans(n);
        
        for(int i = 0; i<n; i++) {
            if(i == 0) ans[vp[i].second] = "Gold Medal";
            else if(i == 1) ans[vp[i].second] = "Silver Medal";
            else if(i == 2) ans[vp[i].second] = "Bronze Medal";
            else ans[vp[i].second] = to_string(i + 1);
        }
        
        return ans;        
    }
};