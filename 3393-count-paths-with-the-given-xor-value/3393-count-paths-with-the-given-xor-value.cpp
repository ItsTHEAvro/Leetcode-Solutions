class Solution {
public:
    const int MOD = 1e9 + 7;

    int countPaths(int i, int j, int xorVal, const vector<vector<int>>& grid, int targetXor, vector<vector<vector<int>>>& dp) {
        if (i == 0 && j == 0) return xorVal == grid[0][0];
        if(i<0 || j<0) return 0;
        if(dp[i][j][xorVal] != -1) return dp[i][j][xorVal];

        int newXorVal = xorVal ^ grid[i][j];
        int fromTop = countPaths(i - 1, j, newXorVal, grid, targetXor, dp);
        int fromLeft = countPaths(i, j - 1, newXorVal, grid, targetXor, dp);

        return dp[i][j][xorVal] = (fromTop + fromLeft) % MOD;
    }

    int countPathsWithXorValue(const vector<vector<int>>& grid, int targetXor) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(16, -1)));
        return countPaths(rows - 1, cols - 1, targetXor, grid, targetXor, dp);
    }
};
