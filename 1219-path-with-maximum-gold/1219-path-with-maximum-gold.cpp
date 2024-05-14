class Solution {
public:
    vector<vector<int>> dir{{-1, 0}, {1,0}, {0, 1}, {0, -1}};
    
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n) {
        if(i >= m || i < 0 || j >= n || j < 0 || grid[i][j] == 0) return 0;
        
        int curr = grid[i][j];
        grid[i][j] = 0;
        
        int mx = 0;
        
        for(auto&d:dir) {
            int tmp_i = i + d[0];
            int tmp_j = j + d[1];
            mx = max(mx, dfs(grid, tmp_i, tmp_j, m, n));
        }
        
        grid[i][j] = curr;
        return curr + mx;
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        int ans = 0;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] != 0) {
                    ans = max(ans, dfs(grid, i, j, m, n));
                }
            }
        }
        
        return ans;
    }
};