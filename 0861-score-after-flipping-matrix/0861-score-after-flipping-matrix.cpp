class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size();
        
        for(int i=0; i<r; i++) {
            if(grid[i][0]==0) {
                for(int j=0; j<c; j++) {
                    grid[i][j] = 1 - grid[i][j];
                }
            }
        }
        
        for(int i=1; i<c; i++) {
            int cntZero = 0;
            for(int j=0; j<r; j++) {
                if(grid[j][i] == 0) cntZero++;
            }
            
            int cntOne = r - cntZero;
            if(cntZero > cntOne) {
                for(int j=0; j<r; j++) {
                    grid[j][i] = 1 - grid[j][i];
                }
            }
        }
        
        int ans = 0;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++) {
                int val = grid[i][j] << (c-j-1);
                ans += val;
            }
        }
        
        return ans;
    }
};