class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0){
            return 0;
        }

        vector<int> lastIdx(255, -1);
        int l = 0;
        int maxLen = 1;
        lastIdx[s[l]] = 0;

        int r = 1;
        int lastCurrIdx = -1;

        for (r = 1; r < s.size(); r++) {
            int lastOccIdx = getLastOccIdx(s[r], lastIdx);

            if (lastOccIdx != -1 && lastOccIdx > lastCurrIdx) {
                maxLen = max(maxLen, r - l);
                l = lastOccIdx + 1;
                lastCurrIdx = lastOccIdx;
            }

            lastIdx[s[r]] = r; 
        }

        return max(maxLen, r - l);
    }

    int getLastOccIdx(char c, vector<int>& arr) { return arr[c]; }
};
