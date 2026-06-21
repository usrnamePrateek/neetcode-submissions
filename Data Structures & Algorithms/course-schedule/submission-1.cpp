class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adjList(numCourses, vector<int>());

        for (auto& preq : prerequisites) {
            adjList[preq[1]].push_back(preq[0]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> pathTaken(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!visited[i] && hasCycle(adjList, i, visited, pathTaken)) {
                return false;
            }
        }

        return true;
    }

    bool hasCycle(vector<vector<int>>& adjList, int i, vector<bool>& visited,
                  vector<bool>& pathTaken) {
        if (pathTaken[i]) {
            return true;
        }

        if (visited[i]) return false;

        visited[i] = true;
        pathTaken[i] = true;
        bool flag = false;
        for (int& neigh : adjList[i]) {
            if (hasCycle(adjList, neigh, visited, pathTaken)) {
                flag = true;
                break;
            }
        }

        pathTaken[i] = false;
        return flag;
    }
};
