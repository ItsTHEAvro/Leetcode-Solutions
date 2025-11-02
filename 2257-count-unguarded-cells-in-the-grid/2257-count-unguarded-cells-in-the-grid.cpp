class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (const auto& g : guards) {
            grid[g[0]][g[1]] = 1;
        }
        for (const auto& w : walls) {
            grid[w[0]][w[1]] = 2;
        }

        int dr[] = {0, 0, 1, -1};
        int dc[] = {1, -1, 0, 0};

        for (const auto& g : guards) {
            for (int i = 0; i < 4; ++i) {
                int r = g[0] + dr[i];
                int c = g[1] + dc[i];

                while (r >= 0 && r < m && c >= 0 && c < n) {
                    int state = grid[r][c];

                    if (state == 1 || state == 2) {
                        break;
                    }

                    if (state == 0) {
                        grid[r][c] = 3;
                    }

                    r += dr[i];
                    c += dc[i];
                }
            }
        }

        int ans = 0;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (grid[r][c] == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};