class Solution {
   public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26, 0);

        for (char& c : s1) {
            freq[c - 'a']++;
        }

        int l = 0;
        for (int r = 0; r < s2.size(); r++) {
            freq[s2[r] - 'a']--;

            while (l <= r && !isGood(freq)) {
                freq[s2[l] - 'a']++;
                l++;
            }

            if (isPassed(freq)) {
                return true;
            }
        }

        return false;
    }

    bool isGood(vector<int>& freq) {
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] < 0) {
                return false;
            }
        }

        return true;
    }

    bool isPassed(vector<int>& freq) {
        for (int i = 0; i < freq.size(); i++) {
            if (freq[i] != 0) {
                return false;
            }
        }

        return true;
    }
};
