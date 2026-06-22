class Solution {
   public:
    vector<int> dp;
    bool wordBreak(string s, vector<string>& wordDict) {
        dp.resize(s.size(), -1);
        unordered_set<string> wordDictSet;
        for (string& word : wordDict) {
            wordDictSet.insert(word);
        }
        return sol(s, 0, wordDictSet);
    }

    bool sol(string& s, int partIdx, unordered_set<string>& wordDict) {
        if (partIdx == s.size()) {
            return true;
        }

        if (dp[partIdx] != -1) {
            return dp[partIdx] == 1;
        }

        string str = "";
        bool res = false;
        for (int i = partIdx; i < s.size(); i++) {
            str.push_back(s[i]);
            if (wordDict.count(str) && sol(s, i + 1, wordDict)) {
                dp[partIdx] = 1;
                return true;
            }
        }

        return dp[partIdx] = res;
    }
};
