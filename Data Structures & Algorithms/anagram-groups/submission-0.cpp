class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> resMap;
        vector<vector<string>> res;
        for (auto& str : strs) {
            string sortedStr = str;
            sort(sortedStr.begin(), sortedStr.end());
            resMap[sortedStr].push_back(str);
        }

        for (auto& entry : resMap) {
            res.push_back(entry.second);
        }

        return res;
    }
};
