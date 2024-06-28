class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        // Array to store the degree of each node
        vector<int> degree(n, 0);
        
        // Calculating the degree of each node
        for(const auto& road:roads) {
            degree[road[0]]++;
            degree[road[1]]++;
        }
        
        // Sorting the array in decreasing order 
        // in order to maximize the importance of the node with the highest degree
        sort(degree.rbegin(), degree.rend());
        
        long long ans = 0;
        
        // Calculating maximum total importance
        for(int i=0; i<n; i++) {
            if(degree[i]) {
                ans += (long long)(n-i) * degree[i];
            } else {
                // If degree of a node doesn't exist, break the loop
                break;
            }
        }
        
        return ans;
    }
};