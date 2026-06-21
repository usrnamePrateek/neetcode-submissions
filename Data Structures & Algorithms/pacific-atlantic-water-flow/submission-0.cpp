class Solution {
public:
    vector<vector<int>> dirs{{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& h, int r, int c,
             vector<vector<bool>>& vis) {

        int m = h.size(), n = h[0].size();

        if (vis[r][c]) return;
        vis[r][c] = true;

        for (auto& d : dirs) {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr < 0 || nc < 0 || nr >= m || nc >= n)
                continue;

            if (h[nr][nc] < h[r][c])
                continue;

            dfs(h, nr, nc, vis);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pac(m, vector<bool>(n,false));
        vector<vector<bool>> atl(m, vector<bool>(n,false));

        // Pacific
        for (int i = 0; i < m; i++) {
            dfs(heights, i, 0, pac);
            dfs(heights, i, n - 1, atl);
        }

        // Atlantic
        for (int j = 0; j < n; j++) {
            dfs(heights, 0, j, pac);
            dfs(heights, m - 1, j, atl);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pac[i][j] && atl[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};