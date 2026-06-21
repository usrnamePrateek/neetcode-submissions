class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        vector<unordered_set<int>> adj(26);
        vector<int> indegree(26, 0);
        unordered_set<int> chars;

        for (auto& word : words) {
            for (char c : word) {
                chars.insert(c - 'a');
            }
        }

        for (int i = 0; i < words.size() - 1; i++) {
            string& w1 = words[i];
            string& w2 = words[i + 1];

            int j = 0;
            while (j < w1.size() && j < w2.size() &&
                   w1[j] == w2[j]) {
                j++;
            }

            if (j == w2.size() && w1.size() > w2.size()) {
                return "";
            }

            if (j < w1.size() && j < w2.size()) {
                int u = w1[j] - 'a';
                int v = w2[j] - 'a';

                if (!adj[u].count(v)) {
                    adj[u].insert(v);
                    indegree[v]++;
                }
            }
        }

        queue<int> q;

        for (int c : chars) {
            if (indegree[c] == 0) {
                q.push(c);
            }
        }

        string res;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            res.push_back('a' + node);

            for (int neigh : adj[node]) {
                indegree[neigh]--;

                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        if (res.size() != chars.size()) {
            return "";
        }

        return res;
    }
};