class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size();
        
        vector<vector<int>> res;
        
        for(int r=0; r<n; r++) {
            for(int c=0; c<m; c++) {
                if(land[r][c]) {
                    int tmpR = r;
                    int tmpC = c;
                    
                    for(tmpR=r; tmpR<n && land[tmpR][c]; tmpR++) {
                        for(tmpC=c; tmpC<m && land[tmpR][tmpC]; tmpC++) {
                            land[tmpR][tmpC] = 0;
                        }
                    }
                    
                    res.push_back({r, c, tmpR - 1, tmpC - 1});
                }
            }
        }
        
        return res;
    }
};