class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int col = grid.size(), row = grid[0].size(), res = 0;
        for (int j = 0;  j < col; j++) {
            for (int i = 0;  i< row; i++) {
                if (grid[j][i] == 1)
                    res = max(res, dfs(j, i, grid));
            }
        }
        return res;
    }
    
    int dfs(int j, int i, vector<vector<int>>& grid) {
        int x[] = {1, 0, -1, 0};
        int y[] = {0, -1, 0, 1};
        int col = grid.size(), row = grid[0].size(), res = 1;
        grid[j][i] = 2;
        for (int t = 0; t < 4; t++) {
            if (valid(j+x[t], i+y[t], col, row) && grid[j+x[t]][i+y[t]] == 1) {
                res += dfs(j+x[t], i+y[t], grid);
            }
        }
        return res;
    }
    
    bool valid(int x, int y, int maxX, int maxY) {
        return x >= 0 && x < maxX && y >= 0 && y < maxY;
    }
};