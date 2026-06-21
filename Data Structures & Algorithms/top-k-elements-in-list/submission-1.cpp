class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freqMap;
        vector<int> res;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for (int& num : nums) {
            freqMap[num]++;
        }

        auto it = freqMap.begin();
        int i = 0;

        while (i < k) {
            pq.push({it->second, it->first});
            i++;
            it++;
        }

        while (it != freqMap.end()) {
            if (pq.top().first < it->second) {
                pq.pop();
                pq.push({it->second, it->first});
            }
            it++;
        }

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
