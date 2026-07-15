class Solution {
   public:
    int maxCount = 0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    int count = 0;
                    dfs(grid, i, j, count);
                    maxCount = max(maxCount, count);
                }
            }
        }

        return maxCount;
    }

    void dfs(vector<vector<int>>& grid, int i, int j, int& count) {
        if (i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() - 1 || grid[i][j] <= 0) {
            return;
        }

        grid[i][j] = -1;
        count++;
        dfs(grid, i + 1, j, count);
        dfs(grid, i, j + 1, count);
        dfs(grid, i - 1, j, count);
        dfs(grid, i, j - 1, count);
    }
};
