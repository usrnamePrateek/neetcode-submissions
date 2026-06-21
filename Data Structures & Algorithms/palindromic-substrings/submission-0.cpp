class Solution {
   public:
    int countSubstrings(string s) {
        int count = s.size();

        for (int i = 0; i < s.size(); i++) {
            int a = i - 1;
            int b = i + 1;

            while (a >= 0 && b < s.size()) {
                if (s[a] == s[b]) {
                    a--;
                    b++;
                    count++;
                } else {
                    break;
                }
            }

            a = i;
            b = i + 1;

            while (a >= 0 && b < s.size()) {
                if (s[a] == s[b]) {
                    a--;
                    b++;
                    count++;
                } else {
                    break;
                }
            }
        }

        return count;
    }
};
