class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        
        for(const auto& road:roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        
        sort(degree.rbegin(), degree.rend());
        
        long long ans = 0;
        
        for(int i=0; i<n; i++) {
            if(degree[i]) {
                ans += (long long)(n-i) * degree[i];
            } else {
                break;
            }
        }
        
        return ans;
    }
};