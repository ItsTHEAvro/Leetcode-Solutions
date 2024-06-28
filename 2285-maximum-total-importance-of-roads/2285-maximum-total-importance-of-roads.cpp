class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<int> arr(n, 0);
        
        for(vector<int> road:roads) {
            for(int node:road) {
                arr[node]++;
            }
        }
        
        sort(arr.rbegin(), arr.rend());
        
        
        long long ans = 0;
        
        for(int i=0; i<n; i++) {
            if(arr[i]) {
                ans += (long long)(n-i) * (long long)arr[i];
            }
        }
        
        return ans;
    }
};