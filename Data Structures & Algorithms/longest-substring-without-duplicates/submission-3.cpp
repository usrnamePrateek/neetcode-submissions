class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIdx(255, -1);
        int l = 0;
        int maxLen = 0;

        for (int r = 0; r < s.size(); r++) {
            if (lastIdx[s[r]] >= l) {
                l = lastIdx[s[r]] + 1;
            }

            lastIdx[s[r]] = r;
            maxLen = max(maxLen, r - l + 1);
        }

        return maxLen;
    }
};
