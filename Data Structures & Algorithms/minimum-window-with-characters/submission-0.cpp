class Solution {
   public:
    string minWindow(string s, string t) {
        unordered_map<char, int> tmp;
        unordered_map<char, int> smp;

        for (char& c : t) {
            tmp[c]++;
        }

        int l = 0;
        int count = 0;
        int minL = -1;
        int minLen = INT_MAX;

        for (int r = 0; r < s.size(); r++) {
            smp[s[r]]++;

            if (tmp.count(s[r]) && smp[s[r]] <= tmp[s[r]]) {
                count++;
            }

            while (count == t.size()) {
                if (minLen > r - l + 1) {
                    minLen = r - l + 1;
                    minL = l;
                }

                smp[s[l]]--;
                if (tmp.count(s[l]) && smp[s[l]] < tmp[s[l]]) {
                    count--;
                }
                l++;
            }
        }

        return minL == -1 ? "" : s.substr(minL, minLen);
    }
};
