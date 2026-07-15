class Solution {
   public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjList(n + 1, vector<pair<int, int>>());
        for (auto& edge : times) {
            adjList[edge[0]].push_back({edge[1], edge[2]});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, k});

        vector<int> dist(n + 1, 1e9);

        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();

            int src = node[1];

            if (dist[src] != 1e9) {
                continue;
            }

            dist[src] = node[0];

            for (auto& neigh : adjList[src]) {
                if (dist[neigh.first] > neigh.second + dist[src]) {
                    int dist_ = neigh.second + dist[src];
                    pq.push({dist_, neigh.first});
                }
            }
        }

        int maxDist = INT_MIN;
        for (int i = 1; i < dist.size(); i++) {
            // cout << dist[i] << " ";
            maxDist = max(maxDist, dist[i]);
        }

        return maxDist == 1e9 ? -1 : maxDist;
    }
};
