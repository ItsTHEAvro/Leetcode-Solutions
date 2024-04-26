class Solution {
public:
    int n;
    int gr[201][201];
    int solve(vector<vector<int>>& grid, int row, int col) {
        if(row ==  n-1) return grid[row][col];
        if(gr[row][col] != -1) return gr[row][col];
        
        int ans = INT_MAX;
        
        for(int i = 0; i<n; i++) {
            if(i != col) ans = min(ans, solve(grid, row+1, i));
        }
        
        return gr[row][col] = ans + grid[row][col];
    }
    
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        memset(gr, -1, sizeof(gr));
        
        int ans = INT_MAX;
        
        for(int i=0; i<n; i++) {
            ans = min(ans, solve(grid, 0, i));
        }
        
        return ans;
    }
};