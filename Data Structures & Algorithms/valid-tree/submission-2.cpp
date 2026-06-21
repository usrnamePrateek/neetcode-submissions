class Solution {
   public:
    bool validTree(int n, vector<vector<int>>& edges) {
        int nEdges = 0;
        vector<vector<int>> adjList(n, vector<int>());

        for (auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
            nEdges++;
        }

        vector<bool> visited(n, false);

        if (nEdges != n - 1) {
            return false;
        }

        if (hasCycle(adjList, 0, -1, visited)) {
            return false;
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                return false;
            }
        }

        return true;
    }

    bool hasCycle(vector<vector<int>>& adjList, int src, int parent, vector<bool>& visited) {
        visited[src] = true;
        for (int& neigh : adjList[src]) {
            if ((visited[neigh] && neigh != parent) ||
                (!visited[neigh] && hasCycle(adjList, neigh, src, visited))) {
                return true;
            }
        }

        return false;
    }
};
