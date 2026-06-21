class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' & !visited[i][j]) {
                    sol(grid, i, j, visited);
                    count++;
                }
            }
        }

        return count;
    }

    void sol(vector<vector<char>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if (i < 0 || j < 0 || i > grid.size() - 1 || j > grid[0].size() - 1 || grid[i][j] == '0' || visited[i][j]) {
            return;
        }

        visited[i][j] = true;
        sol(grid, i + 1, j, visited);
        sol(grid, i - 1, j, visited);
        sol(grid, i, j + 1, visited);
        sol(grid, i, j - 1, visited);
    }
};
