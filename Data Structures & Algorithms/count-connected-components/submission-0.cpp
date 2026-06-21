class Solution {
   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<bool> visited(n, false);
        vector<vector<int>> adjList(n, vector<int>());

        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(adjList, i, visited);
                count++;
            }
        }

        return count;
    }

    void dfs(vector<vector<int>>& adjList, int src, vector<bool>& visited) {
        visited[src] = true;
        for (int& neigh : adjList[src]) {
            if (!visited[neigh]) {
                dfs(adjList, neigh, visited);
            }
        }
    }
};
